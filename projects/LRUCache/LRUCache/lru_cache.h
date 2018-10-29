/*
* Copyright 2018 ByteChen. All rights reserved.
*
* Licensed under the BSD 3-Clause License (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     https://opensource.org/licenses/BSD-3-Clause
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#ifndef _MY_LRU_CACHE_H_
#define _MY_LRU_CACHE_H_

#include<unordered_map>
#include<list>
#include<utility>
#include<iostream>

namespace My_LRU_Cache {
template<class KEY, class VALUE>
class LRUCache {
public:
    typedef typename std::pair<KEY, VALUE> PAIR;
    typedef typename std::list<PAIR>::iterator ITER;

    explicit LRUCache(size_t capacity):m_iCapacity(capacity) {}

    VALUE Get(KEY key) {
        if (m_mapDict.find(key) == m_mapDict.end()) {
            std::cerr << "No such key.";
            return VALUE(); // û�ҵ����򷵻�һ��Ĭ�Ϲ���Ķ���
        }
        VALUE result = m_mapDict[key]->second;
        // m_lstData.push_back(std::make_pair(key, result));
        // m_lstData.erase(m_mapDict[key]);
        // m_mapDict[key] = --m_lstData.end();

        // �����������ʹ��splice��������ʡȥ����Ĳ��裬�ҵ�����Ҳû��ʧЧ
        m_lstData.splice(m_lstData.end(), m_lstData, m_mapDict[key]);
        return result;
    }

    void Put(KEY key, VALUE value) {
        // cache���Ѵ��ڴ�key
        if (m_mapDict.find(key) != m_mapDict.end()) {
            // ��value����ȣ���ɾ���þɼ�¼�������¼�¼; Ҫ��VALUE�������� != ������
            if (m_mapDict[key]->second != value) {
                m_lstData.erase(m_mapDict[key]);
                m_lstData.push_back(std::make_pair(key, value));
                m_mapDict[key] = --m_lstData.end();
            } else {    // value��ȣ�ֻ���������н��ü�¼�ƶ���β������
                m_lstData.splice(m_lstData.end(), m_lstData, m_mapDict[key]);
            }
            return;
        }

        // cache�������ȴ�list��ͷ��map��ɾ�����û�ù��ļ�¼
        if (m_lstData.size() == m_iCapacity) {
            KEY oldKey = m_lstData.begin()->first;
            m_lstData.pop_front();
            m_mapDict.erase(oldKey);
        }

        // �����¼�¼
        m_lstData.push_back(std::make_pair(key, value));
        m_mapDict[key] = --m_lstData.end();
        return;
    }

    // Ϊ����������Ӵ�ӡ���������ϵ��´�ӡcache�еļ�¼
    void PrintRecords() const {
        for (auto iter : m_lstData) {
            std::cout << iter.first << '\t' << iter.second << std::endl;
        }
    }

private:
    size_t m_iCapacity;
    std::list<PAIR> m_lstData;
    std::unordered_map<KEY, ITER> m_mapDict;
};

} // namespace My_LRU_Cache

#endif // _MY_LRU_CACHE_H_

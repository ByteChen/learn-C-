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
#include "lru_cache.h"
//
//namespace My_LRU_Cache {
//    template<class KEY, class VALUE>
//    VALUE LRUCache<KEY, VALUE>::Get(KEY key) {
//        if (m_mapDict.find(key) == m_mapDict.end()) {
//            std::cerr << "No such element.\n";
//            return VALUE(); // û�ҵ����򷵻�һ��Ĭ�Ϲ���Ķ���
//        }
//        VALUE result = m_mapDict[key]->second;
//        m_lstData.push_back(make_pair(key, result));
//        m_lstData.erase(m_mapDict[key]);
//        m_mapDict[key] = --m_lstData.end();
//        return result;
//    }
//
//    template<class KEY, class VALUE>
//    void LRUCache<KEY, VALUE>::Put(KEY key, VALUE value) {
//        if (m_mapDict.find(key) != m_mapDict.end()) {   // ��cache���Ѵ��ڴ�key��������value��
//            m_lstData.erase(m_mapDict[key]);
//            m_lstData.push_back(make_pair(key, value));
//            m_mapDict[key] = --m_lstData.end();
//            return;
//        }
//        if (m_lstData.size() < m_iCapacity) {   // cache��δ���ڴ�key����δ����ֱ�Ӳ��뼴��
//            m_lstData.push_back(make_pair(key, value));
//            m_mapDict[key] = --m_lstData.end();
//            return;
//        }
//        // cache��������Ҫɾ�����û�ù��ļ�¼
//        KEY oldKey = m_lstData.begin()->first;
//        m_lstData.pop_front();
//        m_mapDict.erase(oldKey);
//        m_lstData.push_back(make_pair(key, value));
//        m_mapDict[key] = --m_lstData.end();
//        return;
//    }
//} // My_LRU_Cache
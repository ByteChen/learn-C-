## [146. LRU Cache](https://leetcode.com/problems/lru-cache/description/)
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:
```
LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
```

## 代码
* 思路比较简单，就是 hash表 + list。这个题在腾讯实习生二面遇到过。 list中存储数据，最近使用过的放在表头。C++ 中hash表使用unordered_map实现，unordered_map中value部分存储list的迭代器，
**注意list中每个节点不仅存储数据，还要存储key！！**，这样删除链表节点时能够很快找到对应的要删除的map中的节点。
```C++
class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        curSize = 0;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()){     //若存在，读取并将节点更新到表头。
            int res = m[key]->second;
            ls.erase(m[key]);
            ls.push_front(make_pair(key, res));   //这行使用 ls.emplace_front(key, value) 会更加高效！
            m[key] = ls.begin();
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){     //若存在，由于可能仅是key相等，value不相等，干脆删除旧的，建立新的
            ls.erase(m[key]);
            ls.push_front(make_pair(key, value));
            m[key] = ls.begin();
        }
        else if(curSize < capacity){    //还有空间，插入新节点
            curSize ++;
            ls.push_front(make_pair(key, value));     //这行使用 ls.emplace_front(key, value) 会更加高效！
            m[key] = ls.begin();
        }
        else{                           //没有空间了，删除最老的节点，插入新节点
            auto iter = ls.rbegin();    //此处需要注意，若list中仅仅存储value值，没有存储对应的key值，
            int oldKey = iter->first;   //那么为了删除map中该条记录，需要遍历整个map去比较。性能降低
            ls.erase(m[oldKey]);        //这行实际可以替代为：ls.pop_back();
            m.erase(m.find(oldKey));    //这行也不用先求迭代器，直接：m.erase(oldKey) 即可！因为erase（）可以接受迭代器和
            
            ls.push_front(make_pair(key, value));   //这行使用 ls.emplace_front(key, value) 会更加高效！
            m[key] = ls.begin();
        }
    }

private:
    int curSize;
    int capacity;
    typedef pair<int, int> PA;
    unordered_map<int, list<PA>::iterator> m;
    list<PA> ls;
};
```

#### 附上讨论区中别人的优雅的C++代码，[链接](https://leetcode.com/problems/lru-cache/discuss/45912/Clean-Short-Standard-C++-solution-NOT-writing-C-in-C++-like-all-other-lengthy-ones)
```C++
class LRUCache{
    size_t m_capacity;
    unordered_map<int,  list<pair<int, int>>::iterator> m_map; //m_map_iter->first: key, m_map_iter->second: list iterator;
    list<pair<int, int>> m_list;                               //m_list_iter->first: key, m_list_iter->second: value;
public:
    LRUCache(size_t capacity):m_capacity(capacity) {
    }
    
    int get(int key) {
        auto found_iter = m_map.find(key);
        if (found_iter == m_map.end()) //key doesn't exist
            return -1;
        m_list.splice(m_list.begin(), m_list, found_iter->second); //move the node corresponding to key to front
        return found_iter->second->second;                         //return value of the node
    }
    
    void set(int key, int value) {
        auto found_iter = m_map.find(key);
        if (found_iter != m_map.end()) //key exists
        {
            m_list.splice(m_list.begin(), m_list, found_iter->second); //move the node corresponding to key to front
            found_iter->second->second = value;                        //update value of the node
            return;
        }
        if (m_map.size() == m_capacity) //reached capacity
        {
           int key_to_del = m_list.back().first; 
           m_list.pop_back();            //remove node in list;
           m_map.erase(key_to_del);      //remove key in map
        }
        m_list.emplace_front(key, value);  //create new node in list
        m_map[key] = m_list.begin();       //create correspondence between key and node
    }
};
```

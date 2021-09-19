/**
 * 146. LRU 缓存机制
 * https://leetcode-cn.com/problems/lru-cache/
 */

#include <list>
#include <unordered_map>
#include <utility>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) : m_capacity(capacity) {}

    int get(int key) {
        auto it = m_tbl.find(key);
        if (it != m_tbl.end()) {
            // 将 m_lru 中 it->second 所指向的元素搬到 m_lru.begin()
            m_lru.splice(m_lru.begin(), m_lru, it->second);
            return it->second->second;
        }

        return -1;
    }

    void put(int key, int value) {
        auto it = m_tbl.find(key);
        if (it != m_tbl.end()) {
            m_lru.splice(m_lru.begin(), m_lru, it->second);
            it->second->second = value;
            return;
        }

        // 最新数据放到链表头
        m_lru.emplace_front(key, value);
        // 保存对应的迭代器
        m_tbl[key] = m_lru.begin();

        // 容量达到上限，删除末尾元素
        if (m_tbl.size() > m_capacity) {
            m_tbl.erase(m_lru.back().first);
            m_lru.pop_back();
        }
    }
private:
    int m_capacity;
    list<pair<int, int>> m_lru;
    // m_tbl[键] = 链表节点的迭代器
    unordered_map<int, list<pair<int, int>>::iterator> m_tbl;
};

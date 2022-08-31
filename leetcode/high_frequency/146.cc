#include <iostream>
#include <unordered_map>
using namespace std;

/*
思路：双向链表+hash表
LRU 缓存机制可以通过哈希表辅以双向链表实现，我们用一个哈希表和一个双向链表维护所有在缓存中的键值对。
·双向链表按照被使用的顺序存储了这些键值对，靠近头部的键值对是最近使用的，而靠近尾部的键值对是最久未使用的。
·哈希表即为普通的哈希映射（HashMap），通过缓存数据的键映射到其在双向链表中的位置。
这样以来，我们首先使用哈希表进行定位，找出缓存项在双向链表中的位置，随后将其移动到双向链表的头部，即可在 O(1)O(1) 的时间内完成 get 或者 put 操作。具体的方法如下：
·对于 get 操作，首先判断 key 是否存在：
    如果 key 不存在，则返回 -1−1；
    如果 key 存在，则 key 对应的节点是最近被使用的节点。通过哈希表定位到该节点在双向链表中的位置，并将其移动到双向链表的头部，最后返回该节点的值。
·对于 put 操作，首先判断 key 是否存在：
    如果 key 不存在，使用 key 和 value 创建一个新的节点，在双向链表的头部添加该节点，并将 key 和该节点添加进哈希表中。然后判断双向链表的节点数是否超出容量，如果超出容量，则删除双向链表的尾部节点，并删除哈希表中对应的项；
    如果 key 存在，则与 get 操作类似，先通过哈希表定位，再将对应的节点的值更新为 value，并将该节点移到双向链表的头部。
*/

struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity): _capacity(capacity), _size(0) {
        // 使用伪头部和伪尾部节点
        _phead = new DLinkedNode();
        _ptail = new DLinkedNode();
        _phead->next = _ptail;
        _ptail->prev = _phead;
    }
    
    int get(int key) {
        if (!_cache.count(key)) {
            return -1;
        }
        // 如果 key 存在，先通过哈希表定位，再移到头部
        DLinkedNode* node = _cache[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (!_cache.count(key)) {
            // 如果 key 不存在，创建一个新的节点
            DLinkedNode* node = new DLinkedNode(key, value);
            // 添加进哈希表
            _cache[key] = node;
            // 添加至双向链表的头部
            addToHead(node);
            ++_size;
            if (_size > _capacity) {
                // 如果超出容量，删除双向链表的尾部节点
                DLinkedNode* removed = removeTail();
                // 删除哈希表中对应的项
                _cache.erase(removed->key);
                // 防止内存泄漏
                delete removed;
                --_size;
            }
        }
        else {
            // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
            DLinkedNode* node = _cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode* node) {
        node->prev = _phead;
        node->next = _phead->next;
        _phead->next->prev = node;
        _phead->next = node;
    }
    
    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail() {
        DLinkedNode* node = _ptail->prev;
        removeNode(node);
        return node;
    }

private:
    unordered_map<int, DLinkedNode*> _cache;
    DLinkedNode* _phead;
    DLinkedNode* _ptail;
    int _size;
    int _capacity;
};

int main(void)
{
    LRUCache lRUCache = LRUCache(2);
    lRUCache.put(1, 1); // 缓存是 {1=1}
    lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
    printf("%d\n", lRUCache.get(1));    // 返回 1
    lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    printf("%d\n", lRUCache.get(2));    // 返回 -1 (未找到)
    lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    printf("%d\n", lRUCache.get(1));    // 返回 -1 (未找到)
    printf("%d\n", lRUCache.get(3));    // 返回 3
    printf("%d\n", lRUCache.get(4));    // 返回 4

    return 0;
}
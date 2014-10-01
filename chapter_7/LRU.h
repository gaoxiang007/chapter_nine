// https://oj.leetcode.com/problems/lru-cache/

struct CacheNode {
    int _key;
    int _val;
    CacheNode(int key, int val) : _key(key), _val(val) {}
};

class LRUCache{
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        
    }
    
    void set(int key, int value) {
        
    }
private:
    int _capacity;
    list<CacheNode*> cache_list;
    unordered_map<int, list<CacheNode*>::iterator > cache_map;
};

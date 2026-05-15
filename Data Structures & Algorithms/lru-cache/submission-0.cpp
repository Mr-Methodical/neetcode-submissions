class Node {
public:
    int key;
    int val;
    Node *prev;
    Node *next;
    Node(int k, int v) {
        key = k;
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};
class LRUCache {
private:
    int cap;
    unordered_map<int, Node *> cache;
    Node *left;
    Node *right;

    void remove(Node *node) {
        Node *prev = node->prev;
        Node *nxt = node->next;
        prev->next = nxt;
        nxt->prev = prev;
        // we skip over that node and then we are done
    }
    
    void insert(Node *node) {
        // right is LRU
        Node *prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (cache.contains(key)) {
            Node *node = cache[key];
            remove(node);
            insert(node);
            // so we update it basically
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.contains(key)) {
            remove(cache[key]);
        }
        Node *new_node = new Node(key, value);
        cache[key] = new_node;
        insert(new_node);
        if (cache.size() > cap) {
            Node *lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};

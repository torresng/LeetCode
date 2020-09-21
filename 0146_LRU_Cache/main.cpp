class LRUCache {
    struct Node {
        int key;
        int value;
        Node *prev;
        Node *next;
        Node(int key, int value, Node *prev, Node *next) {
            this->key = key;
            this->value = value;
            this->prev = prev;
            this->next = next;
        }
    };
    Node *head = new Node(-1, -1, nullptr, nullptr);
    unordered_map<int, Node *> map;

    void moveTail(Node *cur) {
        if (cur == head) {
            head = head->next;
            return;
        }
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;

        cur->next = head;
        cur->prev = head->prev;
        head->prev->next = cur;
        head->prev = cur;
    }

  public:
    LRUCache(int capacity) {
        Node *cur = head;
        for (int i = 0; i < capacity - 1; i++) {
            cur->next = new Node(-1, -1, cur, nullptr);
            cur = cur->next;
        }
        cur->next = head;
        head->prev = cur;
    }

    int get(int key) {
        if (map.count(key) == 0) {
            return -1;
        }
        Node *cur = map[key];
        moveTail(cur);
        return cur->value;
    }

    void put(int key, int value) {
        if (map.count(key) != 0) {
            Node *cur = map[key];
            cur->value = value;
            moveTail(cur);
        } else {
            if (head->value != -1) {
                map.erase(head->key);
            }
            head->key = key;
            head->value = value;
            map[key] = head;
            head = head->next;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

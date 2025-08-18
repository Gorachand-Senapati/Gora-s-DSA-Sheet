class LRUCache {
public:
    // Doubly Linked List Node
    class Node {
    public:
        int key, val;
        Node* next;
        Node* prev;

        Node(int k, int v) {
            key = k;
            val = v;
            next = prev = NULL;
        }
    };

    Node* head = new Node(-1, -1); // dummy head
    Node* tail = new Node(-1, -1); // dummy tail
    unordered_map<int, Node*> m;   // key -> node reference
    int limit;

    // Insert node right after head
    void addafterHead(Node* newNode) {
        Node* oldNode = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = oldNode;
        oldNode->prev = newNode;
    }

    // Remove node from list
    void deleteNode(Node* oldNode) {
        Node* afterNode = oldNode->next;
        Node* beforeNode = oldNode->prev;
        beforeNode->next = afterNode;
        afterNode->prev = beforeNode;
    }

    LRUCache(int cap) {
        limit = cap;
        head->next = tail;
        tail->prev = head;
    }
    int get(int key) {
        if (m.find(key) == m.end()) return -1; // not found
        Node* ansNode = m[key];
        int ans = ansNode->val;

        // move to front (most recently used)
        deleteNode(ansNode);
        addafterHead(ansNode);
        m[key] = ansNode;

        return ans;
    }
    void put(int key, int value) {
        if (m.find(key) != m.end()) { // key already exists
            Node* oldNode = m[key];
            deleteNode(oldNode);
            m.erase(key);
        }

        if (m.size() == limit) { // cache is full
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node* newNode = new Node(key, value);
        addafterHead(newNode);
        m[key] = newNode;
    }
};

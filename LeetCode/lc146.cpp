class LRUCache {
public:
    struct Node
    {
        int key, val;
        Node *left, *right;
        Node(int key_ = -1, int val_ = -1)
            : key(key_),
              val(val_),
              left(nullptr),
              right(nullptr)
        {}
    }*l, *r;

    unordered_map<int, Node*> mp;
    int n;
    LRUCache(int capacity) {
        n = capacity;
        l = new Node();
        r = new Node();
        l->right = r;
        r->left = l;
    }

    void remove(Node *a)
    {
        a->left->right = a->right;
        a->right->left = a->left;
    }

    void insert(Node *a)
    {
        a->left = l;
        a->right = l->right;
        l->right->left = a;
        l->right = a;
    }
    
    int get(int key) {
        if (mp.count(key) != 0)
        {
            auto p = mp[key];
            remove(p);
            insert(p);
            return p->val;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        if (mp.count(key) != 0)
        {
            auto p = mp[key];
            p->val = value;
            remove(p);
            insert(p);
        }
        else
        {
            if (mp.size() == n)
            {
                auto p = r->left;
                remove(p);
                mp.erase(p->key);
            }
            Node *tmp = new Node(key, value);
            mp[key] = tmp;
            insert(tmp);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

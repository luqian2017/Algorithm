struct Node {
    int key;
    int value;
    struct Node *prev, *next;
    Node(int k, int v) : key(k), value(v), prev(NULL), next(NULL) {}
};

class LRUCache {
public:
    /*
    * @param capacity: An integer
    */
    LRUCache(int capacity) : cap(capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;   
    }

    /*
     * @param key: An integer
     * @return: An integer
     */
    int get(int key) {
       // cout << "get(" << key << ")" << endl;
        if (mp.find(key) != mp.end()) {
            Node *node = mp[key];
            node->prev->next = node->next;
            node->next->prev = node->prev;
            move2Tail(node);
            return node->value;
        } else {
            return -1;
        }
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
       // cout << "set(" << key << ", " << value << ")" << " cap=" << cap << endl;


        if (mp.find(key) == mp.end()) {
            
                //cap++;
                //move2Tail(mp[key]);
            if (mp.size() == cap) {
           // cout << " del " << head->next->key << endl;
                mp.erase(head->next->key);
                Node *node = head->next->next;
                node->prev = head;
                head->next = node;
            //cap--;
            }
            mp[key] = new Node(key, value);     
        } else {
                Node * node = mp[key];
                node->value = value;
                node->prev->next = node->next;
                node->next->prev = node->prev;
                //move2Tail(mp[key]);
        }
        move2Tail(mp[key]);
        
    }

private:
    Node *head, *tail;
    unordered_map<int, Node*> mp;
    int cap;
    void move2Tail(Node *node) {
     //   cout << "  move2Tail(" << node->key << ")" << endl;
        Node *prevTail = tail->prev;
        prevTail->next = node;
        node->prev = prevTail;
        tail->prev = node;
        node->next = tail;
        //debug
    #if 0
        cout << "   list:"<<endl;
        if (head->next) {
            cout << " 0 " << head->next->key;
            if (head->next->next) {
                cout << " " << head->next->next->key;
                if (head->next->next->next) {
                    cout << " " << head->next->next->next->key;
                    if (head->next->next->next->next) {
                        cout << " " << head->next->next->next->next->key;
                        cout << endl;
                    }
                    cout << endl;
                }
                cout << endl;
            }
            cout << endl;
        }
    #endif
    }
    
};
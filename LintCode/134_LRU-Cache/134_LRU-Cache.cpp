class Node {
public:
    Node *prev;
    Node *next;
    int key;
    int val;
    Node(int k = 0, int v = 0) : key(k), val(v), prev(NULL), next(NULL) {}
};

class LRUCache {
public:
    /*
    * @param capacity: An integer
    */
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->head = new Node;  //dummy node
        this->tail = new Node;  //dummy node
        head->next = tail;
        tail->prev = head;
    }

    /*
     * @param key: An integer
     * @return: An integer
     */
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        Node *findNode = mp[key];
      //  findNode->prev->next = findNode->next;
      //    findNode->next->prev = findNode->prev;
        moveToTail(findNode);
        return findNode->val;
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key]->val = value;
            moveToTail(mp[key]);
            return;
        } else if (mp.size() == capacity) { //LRU full, remove the least used node
            mp.erase(head->next->key);
            head->next = head->next->next;
            head->next->prev = head;
        }
        
        Node * node = new Node(key, value);
        mp[key] = node;
        moveToTail(node);
    }
    
private:
   Node *head, *tail;
   int capacity;
   map<int, Node *> mp;
   
   void moveToTail(Node * node) {
       if (node->prev) node->prev->next = node->next;
       if (node->next) node->next->prev = node->prev;
       
       node->prev = tail->prev;
       tail->prev->next = node;
       tail->prev = node;
       node->next = tail;
   }
};
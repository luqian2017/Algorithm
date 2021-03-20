class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        //size = k;
        //data = new int[k + 1];
        //head = 0;
        //tail = 0;
        //cnt = 0;
        size = k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
       // if (cnt == size) return false;
       // data[head] = value;
       // head = (head - 1 + size) % size;
       // cnt++;
        if (size == data.size()) return false;
       // data.push_front(value);
        data.insert(data.begin(), value);
        //size++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (size == data.size()) return false;
        data.push_back(value);
       // size++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) return false;
        //head = (head + 1) % size;
        //data.pop_front();
        data.erase(data.begin());
      //  size--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) return false;
        data.pop_back();
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
       // return *data.begin();
        if (isEmpty()) return -1;
        return data.front();
        // return *data.begin();
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) return -1;
        return data.back();
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return data.empty();
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size == data.size();
    }
    
private:
    vector<int> data;
    int size;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
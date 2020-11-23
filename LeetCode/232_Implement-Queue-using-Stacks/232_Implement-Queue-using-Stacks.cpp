class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stk1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int top_elem;
        if (stk2.empty()) {
            while(!stk1.empty()) {
                top_elem = stk1.top();
                stk2.push(top_elem);
                stk1.pop();
            }
        }
        top_elem = stk2.top();
        stk2.pop();
        return top_elem;
    }
    
    /** Get the front element. */
    int peek() {
        int top_elem;
        if (stk2.empty()) {
            while(!stk1.empty()) {
                top_elem = stk1.top();
                stk2.push(top_elem);
                stk1.pop();
            }
        }
        top_elem = stk2.top();
       // stk2.pop();
        return top_elem;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk1.empty() && stk2.empty();
    }
private:
    stack<int> stk1, stk2;
    
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
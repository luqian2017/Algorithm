class MaxStack {
public:
    MaxStack() {
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number) {
        s.push(number);
        max_heap.insert(number);
    }

    /*
     * @return: An integer
     */
    int pop() {

        int top = s.top();
        s.pop();
        int count = max_heap.count(top);
        max_heap.erase(top);
        if (count > 1) {
            for (int i = 1; i < count; ++i) {
                max_heap.insert(top);
            }
        }
        return top;
    }

    /*
     * @return: An integer
     */
    int top() {
        return s.top();
    }
    
    /*
     * @return: An integer
     */
    int peekMax() {
        return *max_heap.rbegin();   //or *(max_heap.end() - 1)
    }
    
    /*
     * @return: An integer
     */
    int popMax() {
        int max_elem = peekMax();
        int count = max_heap.count(max_elem);
        //max_heap.erase(max_heap.rbegin());
        //max_heap.erase(max_heap.end() - 1);
        max_heap.erase(max_elem);
        for (int i = 1; i < count; ++i) {
            max_heap.insert(max_elem);
        }
        
        stack<int> s2;
        while(s.top() != max_elem) {
            s2.push(s.top());
            s.pop();
        }
        s.pop();
        while(!s2.empty()) {
            s.push(s2.top());
            s2.pop();
        }
        return max_elem;
    }
private:
    stack<int> s;
    //priority_queue<int> max_heap;
    multiset<int> max_heap;
};
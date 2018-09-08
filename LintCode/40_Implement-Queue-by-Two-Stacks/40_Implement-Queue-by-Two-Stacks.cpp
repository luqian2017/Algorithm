class MyQueue {
public:
    MyQueue() {
        // do intialization if necessary
    }

    /*
     * @param element: An integer
     * @return: nothing
     */
    void push(int element) {
        s1.push(element);
    }

    /*
     * @return: An integer
     */
    int pop() {
        int num;
        if (s2.empty()) {
            while (!s1.empty()) {
                num = s1.top();
                s1.pop();
                s2.push(num);
            }
        }
        
        if (!s2.empty()) {
            num = s2.top();
            s2.pop();
            return num;
        }
        
        return INT_MIN;
    }

    /*
     * @return: An integer
     */
    int top() {
        int num;
        if (s2.empty()) {
            while (!s1.empty()) {
                num = s1.top();
                s1.pop();
                s2.push(num);
            }
        }
        
        if (!s2.empty())
            return s2.top();
        
        return INT_MIN;
    }

private:
    stack<int> s1, s2;
    
};
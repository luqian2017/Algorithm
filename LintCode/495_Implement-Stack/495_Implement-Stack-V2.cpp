class Stack {
public:
    /*
     * @param x: An integer
     * @return: nothing
     */
    void push(int x) {
        q1.push(x);
    }

    /*
     * @return: nothing
     */
    void pop() {
        int N = q1.size();
        if (N > 1) {
            for (int i = 0; i < N - 1; ++i) {
                q2.push(q1.front());
                q1.pop();
            }
        }
        q1.pop();
        swap(q1, q2);
    }

    /*
     * @return: An integer
     */
    int top() {
        int N = q1.size();
        if (N > 1) {
            for (int i = 0; i < N - 1; ++i) {
                q2.push(q1.front());
                q1.pop();
            }
        }
        
        int top = q1.front();
        q1.pop();
        q2.push(top);
        
        swap(q1, q2);
        
        return top;
    }

    /*
     * @return: True if the stack is empty
     */
    bool isEmpty() {
        return q1.empty();
    }
    
private:
    queue<int> q1, q2;

};
class Stack {
public:
    /*
     * @param x: An integer
     * @return: nothing
     */
    void push(int x) {
        q.push(x);
    }

    /*
     * @return: nothing
     */
    void pop() {
        int N = q.size();
        if (N > 1) {
            for (int i = 0; i < N - 1; ++i) {
                q.push(q.front());
                q.pop();
            }
        }
        q.pop();
    //    swap(q1, q2);
    }

    /*
     * @return: An integer
     */
    int top() {
        int N = q.size();
        if (N > 1) {
            for (int i = 0; i < N - 1; ++i) {
                q.push(q.front());
                q.pop();
            }
        }
        
        int top = q.front();
        q.pop();
        q.push(top);
        
        //swap(q1, q2);
        
        return top;
    }

    /*
     * @return: True if the stack is empty
     */
    bool isEmpty() {
        return q.empty();
    }
    
private:
    queue<int> q;

};
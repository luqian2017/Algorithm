class Stack {
public:
    /*
     * @param x: An integer
     * @return: nothing
     */
    void push(int x) {
        q.push(x);
        int N = q.size();
        for (int i = 0; i < N - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    /*
     * @return: nothing
     */
    void pop() {
      //  int N = q.size();
//        for (int i = 0; i < N - 1; ++i) {
//            q.push(q.front());
//            q.pop();
//        }
        q.pop();
    }

    /*
     * @return: An integer
     */
    int top() {
       // int N = q.size();
    //    for (int i = 0; i < N - 1; ++i) {
    //        q.push(q.front());
    //        q.pop();
    //    }
        return q.front();
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
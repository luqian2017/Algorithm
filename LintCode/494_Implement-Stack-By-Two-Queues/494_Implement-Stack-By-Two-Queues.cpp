class Stack {
public:
    /*
     * @param x: An integer
     * @return: nothing
     */
    void push(int x) {
        if (q1.empty()) {
            q1.push(x);
            while(!q2.empty()) {
                int entry = q2.front();
                q1.push(entry);
                q2.pop();
            }
            return;
        }

        if (q2.empty()) {
            q2.push(x);
            while(!q1.empty()) {
                int entry = q1.front();
                q2.push(entry);
                q1.pop();
            }
            return;
        }
    }

    /*
     * @return: nothing
     */
    void pop() {
        if (!q1.empty()) {
            q1.pop();
            return;
        }

        if (!q2.empty()) {
            q2.pop();
            return;
        }        
    }

    /*
     * @return: An integer
     */
    int top() {
        if (!q1.empty()) {
            return q1.front();
        }
        if (!q2.empty()) {
            return q2.front();
        }
    }

    /*
     * @return: True if the stack is empty
     */
    bool isEmpty() {
        return q1.empty() && q2.empty();
    }

private:
    queue<int> q1;
    queue<int> q2;
};
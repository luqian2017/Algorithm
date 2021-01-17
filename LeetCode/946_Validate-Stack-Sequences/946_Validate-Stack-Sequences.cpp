class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int> s;
        s.push(-1);
        int pushed_index = 0, popped_index = 0;
        while (popped_index < n) {
            while (pushed_index < n && s.top() != popped[popped_index]) {
                s.push(pushed[pushed_index++]);
            }
            if (s.top() == popped[popped_index]) {
                s.pop();
                popped_index++;
            } else {
                return false;
            }
        }
        return s.top() == -1;
    }
};


//it can be rewritten as below
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int> s;
        s.push(-1);
        int push_index = 0;
        for (auto elem : popped) {
            while (push_index < n && s.top() != elem) {
                s.push(pushed[push_index++]);
            }
            if (s.top() == elem) {
                s.pop();
            } else {
                return false;
            }
        }
        return s.top() == -1;
    }
};

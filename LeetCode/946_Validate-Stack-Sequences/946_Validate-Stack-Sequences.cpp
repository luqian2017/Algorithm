class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int> s;
        s.push(-1);
        int pushed_index = 0, popped_index = 0;
        while (popped_index < n) {
            while (popped_index < n && pushed_index < n && s.top() != popped[popped_index]) {
                s.push(pushed[pushed_index++]);
            }
            if (popped_index < n && s.top() == popped[popped_index]) {
                s.pop();
                popped_index++;
            } else {
                return false;
            }
        }
        return s.top() == -1;
    }
};
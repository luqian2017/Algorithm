class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int> s;
        int pop_index = 0;
        for (auto elem : pushed) {
            s.push(elem);
            while (!s.empty() && s.top() == popped[pop_index]) {
                s.pop();
                pop_index++;
            }
        }
        return s.empty();
    }
};

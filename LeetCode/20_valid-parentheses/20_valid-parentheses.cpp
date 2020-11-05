class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            switch (s[i]) {
                case '(':
                case '[':
                case '{':
                    stk.push(s[i]);
                    break;
                case ')':
                    if (stk.empty()) return false;
                    if (stk.top() != '(') return false;
                    stk.pop();
                    break;
                case ']':
                    if (stk.empty()) return false;
                    if (stk.top() != '[') return false;
                    stk.pop();
                    break;
                case '}':
                    if (stk.empty()) return false;
                    if (stk.top() != '{') return false;
                    stk.pop();
                    break;
                default: return false;
            }
        }
        
        return stk.empty();
    }
};
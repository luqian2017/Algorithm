class Solution {
public:
    /**
     * @param s: A string
     * @return: whether the string is a valid parentheses
     */
    bool isValidParentheses(string &s) {
        int len = s.size();
        stack<char> st; 
        
        
        for (int i = 0; i < len; ++i) {
            if ((s[i] == '(') ||
                (s[i] == '{') ||
                (s[i] == '[')) {
                st.push(s[i]);
                continue;
            }
            
            if (st.empty()) return false;
            
            if (s[i] == ')') {
                if (!st.empty()) {
                    if (st.top() != '(') return false;
                    else st.pop();
                }
            } else if (s[i] == '}') {
                if (!st.empty()) {
                    if (st.top() != '{') return false;
                    else st.pop();
                }
            } else if (s[i] == ']') {
                if (!st.empty()) {
                    if (st.top() != '[') return false;
                    else st.pop();
                }
            }
        }
    
        if (!st.empty()) return false;
        return true;
    }
};
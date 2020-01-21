class Solution {
public:
    /**
     * @param s: a string
     * @return: return a integer
     */
    int longestValidParentheses(string &s) {
        int n = s.size();
        stack<int> st; //positions
        int startPos = 0;
        int maxCount = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') st.push(i);
            else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop();
                    if (st.empty()) {
                        maxCount = max(maxCount, i - startPos + 1);
                    } else {
                        maxCount = max(maxCount, i - st.top());
                    }
                } else {
                    // a new valid period starts from i + 1
                    if (i < n - 1) startPos = i + 1; 
                }
            }
        }
        
        return maxCount;
    }
};
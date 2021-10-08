class Solution {
public:
    /**
     * @param S: the given string
     * @return: the minimum number of parentheses we must add
     */
    int minAddToMakeValid(string &S) {
        int n = S.size();
        if (n == 0) return 0;
        stack<char> stk;
        int cnt = 0;
        
        for (int i = 0; i < n; ++i) {
            if (S[i] == '(') {
                stk.push(S[i]);
            } else {
                if (stk.empty()) cnt++;
                else stk.pop();
            }
        }
        cnt += stk.size();
        return cnt;
    }
};
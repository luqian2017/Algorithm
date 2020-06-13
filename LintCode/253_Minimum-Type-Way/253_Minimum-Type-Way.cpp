class Solution {
public:
    /**
     * @param str: the string you wanna print.
     * @return: return the minimum times you need to hit the keyboard.
     */
    int minimumTyping(string &str) {
        int n = str.size();
        vector<int> upper(n);
        vector<int> lower(n);
        
        if (isupper(str[0])) {
            upper[0] = 2;
            lower[0] = 2;
        } else {
            upper[0] = 2;
            lower[0] = 1;
        }

        for (int i = 1; i < n; ++i) {
            if (isupper(str[i])) {
                upper[i] = min(upper[i - 1] + 1, lower[i - 1] + 2);
                lower[i] = min(upper[i - 1] + 2, lower[i - 1] + 2);
            } else {
                upper[i] = min(upper[i - 1] + 2, lower[i - 1] + 2);
                lower[i] = min(upper[i - 1] + 2, lower[i - 1] + 1);
            }
        }
        
        return lower.back();
    }
};
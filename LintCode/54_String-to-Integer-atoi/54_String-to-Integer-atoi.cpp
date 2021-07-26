class Solution {
public:
    /**
     * @param s: A string
     * @return: An integer
     */
    int atoi(string &s) {
        int len = s.size();
        if (len == 0) return 0;
        int res = 0, sign = 1, pos = 0;
        while (pos < len) {
            if (s[pos] != ' ') break;
            pos++;
        }
        if (pos < len && (s[pos] == '-' || s[pos] == '+')) {
            if (s[pos] == '-') sign = -1;
            pos++;
        }
        while (pos < len) {
            if (s[pos] >= '0' && s[pos] <= '9') {
                int num = s[pos] - '0';
                if (res > INT_MAX / 10 || (res == INT_MAX / 10 && num > 7)) {
                    return sign == 1 ? INT_MAX : INT_MIN;
                }
                res = res * 10 + num;
                pos++;
            } else {
                break;
            }
            
        }
        return res * sign;
    }
};
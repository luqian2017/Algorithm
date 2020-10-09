class Solution {
public:
    /**
     * @param str: the string
     * @return: the number of substrings 
     */
    int stringCount(string &str) {
        int len = str.size();
        int range_len = 0, result = 0;

        for (int i = 0; i < len; ++i) {
            if (str[i] == '0') {
                range_len++;
            } else {
                result += range_len * (range_len + 1) / 2;
                range_len = 0;
            }
        }
        if (range_len > 0) result += range_len * (range_len + 1) / 2;
        return result;            
    }
};
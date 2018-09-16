class Solution {
public:
    /**
     * @param str: str: the given string
     * @return: char: the first unique character in a given string
     */
    char firstUniqChar(string &str) {
        vector<int> hm(256, 0); 
        int strSize = str.size();

        for (int i = 0; i < strSize; ++i) {
            hm[str[i]-'0']++;
        }

        for (int i = 0; i < strSize; ++i) {
            if (hm[str[i]-'0'] == 1) return str[i];
        }
    }
};
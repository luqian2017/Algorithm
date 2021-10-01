class Solution {
public:
    /**
     * @param str: str: the given string
     * @return: char: the first unique character in a given string
     */
    char firstUniqChar(string &str) {
        unordered_map<char, int> us;
        int n = str.size();
        for (int i = 0; i < n; ++i) {
                us[str[i]]++;
        }
        for (int i = 0; i < n; ++i) {
            if (us[str[i]] == 1) return str[i];
        }

    }
};
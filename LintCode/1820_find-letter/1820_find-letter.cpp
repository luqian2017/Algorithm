class Solution {
public:
    /**
     * @param str: the str
     * @return: the letter
     */
    char findLetter(string &str) {
        int n = str.size();
        vector<int> count_lowercase(26, 0);
        vector<int> count_uppercase(26, 0);
        
        for (int i = 0; i < n; ++i) {
            if (str[i] >= 'a' && str[i] <= 'z') count_lowercase[str[i] - 'a']++;
            else count_uppercase[str[i] - 'A']++;
        }

        for (int i = 25; i >= 0; --i) {
            if (count_lowercase[i] > 0 && count_uppercase[i] > 0) {
                return 'A' + i;
            }
        }
        
        return '~';
    }
};
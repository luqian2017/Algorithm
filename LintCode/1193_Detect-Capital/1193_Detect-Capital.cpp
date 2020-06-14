class Solution {
public:
    /**
     * @param word: a string
     * @return: return a boolean
     */
    bool detectCapitalUse(string &word) {
        int n = word.size();
        int upperCount = 0;
        for (int i = 0; i < n; ++i) {
            if (isupper(word[i])) upperCount++;
        }
        if (upperCount == n || upperCount == 0) return true;
        if (n > 0 && upperCount == 1 && isupper(word[0])) return true;
        return false;
    }
};
class Solution {
public:
    /**
     * @param s: the given string
     * @return: all the possible states of the string after one valid move
     */
    vector<string> generatePossibleNextMoves(string &s) {
        int n = s.size();
        if (n < 2) return {};
        vector<string> result;
        for (int pos = 0; pos < n - 1; pos++) {
            if (s[pos] == '+' && s[pos + 1] == '+') {
                s[pos] = '-'; s[pos + 1] = '-';
                result.push_back(s);
                s[pos] = '+'; s[pos + 1] = '+';
            }
        }
        
        return result;
    }
};
class Solution {
public:
    /**
     * @param words: a list of unique words
     * @return: all pairs of distinct indices
     */
    vector<vector<int>> palindromePairs(vector<string> &words) {
        int n = words.size();
        if (n == 0) return {{}};
        vector<vector<int>> result;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
               // string concatStr = words[i] + words[j];
                if (isPalindrome(words[i] + words[j])) result.push_back({i, j});
              //  concatStr = words[j] + words[i];
                if (isPalindrome(words[j] + words[i])) result.push_back({j, i});
            }
        }
        
        return result;
    }

private:
    bool isPalindrome(string s) {
        int n = s.size();
        int p1 = 0, p2 = n - 1;
        while(p1 < p2) {
            if (s[p1] != s[p2]) return false;
            p1++;
            p2--;
        }
        return true;
    }
};
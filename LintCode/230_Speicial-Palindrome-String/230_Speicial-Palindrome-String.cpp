class Solution {
public:
    /**
     * @param ambigram: A list of paired ambigram letter.
     * @param word: A string need to be judged.
     * @return: If it is special palindrome string, return true.
     */
    bool ispalindrome(vector<string> &ambigram, string &word) {
        int m = ambigram.size();
        int n = word.size();
        int start = 0, end = n - 1;
        
        // build the dict        
        unordered_map<char, vector<char>> um;
        for (int i = 0; i < m; ++i) {
            um[ambigram[i][0]].push_back(ambigram[i][0]);
            um[ambigram[i][1]].push_back(ambigram[i][1]);
            if (ambigram[i][0] != ambigram[i][1]) {
                um[ambigram[i][0]].push_back(ambigram[i][1]); 
                um[ambigram[i][1]].push_back(ambigram[i][0]);
            }
        }

        while (start < end) {
            if (word[start] == word[end]) {
                start++;
                end--;
            } else {
                bool occured = false;
                for (int i = 0; i < um[word[start]].size(); ++i) {
                    for (int j = 0; j < um[word[end]].size(); ++j) {
                        if (um[word[start]][i] == um[word[end]][j]) {
                            start++;
                            end--;
                           occured = true;
                           break;
                        }
                    }
                }
                if (!occured) return false;
            }
        }
        
        return true;
    }

};
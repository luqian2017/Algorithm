class Solution {
public:
    /**
     * @param str: the origin string
     * @return: the start and end of every twitch words
     */
    vector<vector<int>> twitchWords(string &str) {
        int n = str.size();
        if (n == 0) return {{}};
        vector<vector<int>> result;
        int pStart = 0, pEnd = 1;
        while(pEnd < n) {
            if (str[pEnd] == str[pStart]) {
                while(pEnd < n && str[pEnd] == str[pStart]) pEnd++;
                if (pEnd - pStart > 2) {
                    result.push_back({pStart, pEnd - 1});
                }
                pStart = pEnd;
                pEnd++;
            } else {
                pStart++;
                pEnd++;
            }
                
        }
        return result;
    }
};
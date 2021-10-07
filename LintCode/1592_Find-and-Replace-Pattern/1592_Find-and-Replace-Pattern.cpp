class Solution {
public:
    /**
     * @param words: word list
     * @param pattern: pattern string
     * @return: list of matching words
     */
    vector<string> findAndReplacePattern(vector<string> &words, string &pattern) {
        int wordsCount = words.size();
        int pattenLen = pattern.size();
        vector<string> res;
        unordered_map<char, char> p2w;   //<patternChar, stringChar>
        unordered_map<char, char> w2p; //<stringChar, patternChar>
        for (int i = 0; i < wordsCount; i++) {
            int wordSize = words[i].size();
            if (wordSize != pattenLen) continue;
            bool meet = true;
            p2w.clear(); w2p.clear();
            for (int j = 0; j < wordSize; ++j) {
                char patternChar = pattern[j];
                char stringChar = words[i][j];
                bool findInPattern = (p2w.find(patternChar) != p2w.end());
                bool findInString = (w2p.find(stringChar) != w2p.end());
                if (!findInPattern && !findInString) {
                    p2w[patternChar] = stringChar;
                    w2p[stringChar] = patternChar;
                } else if (findInString && findInPattern && 
                           p2w[patternChar] == stringChar 
                           && w2p[stringChar] == patternChar) {
                    continue;
                } else {
                    meet = false;
                    break;
                }
            }
            if (meet) res.push_back(words[i]);
        }
        return res;
    }
};
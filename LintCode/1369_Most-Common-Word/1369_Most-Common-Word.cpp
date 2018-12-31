class Solution {
public:
    /**
     * @param paragraph: 
     * @param banned: 
     * @return: nothing
     */
    string mostCommonWord(string &paragraph, vector<string> &banned) {
        int len = paragraph.size();
        int bannedCount = banned.size();
        map<string, int> mp; //word, count;
        set<string> s(banned.begin(), banned.end()); //banned set
    
        to_lower_letter(paragraph);
        for (int i = 0; i < bannedCount; ++i) {
            to_lower_letter(banned[i]);
        }
        
        int begPos = 0, endPos = 0;
        int boundary = len - 1;
        for (int i = 0; i < boundary; ++i) {
            string word;
            if (is_lower_letter((char)paragraph[i])) {
                if (!is_lower_letter((char)paragraph[i + 1])) {
                    endPos = i;
                    word = paragraph.substr(begPos, endPos - begPos + 1);
                } else if (i == len - 2) {
                    endPos = boundary;
                    word = paragraph.substr(begPos, endPos - begPos + 1);
                }

                if (word.size() > 0) {
                    if (s.find(word) == s.end()) {
                        if (mp.find(word) == mp.end()) {
                            mp[word] = 1;     
                        } else {
                            mp[word]++;
                        }
                    }
                }
            } else if (!is_lower_letter((char)paragraph[i]) && is_lower_letter((char)paragraph[i + 1])) {
                begPos = i + 1;
            } else {
                continue;
            }
        }
        
        int maxCount = INT_MIN;
        string result;
        for (auto m : mp) {
            if (m.second > maxCount) {
                result = m.first;
                maxCount = m.second;
            }
        }
        
        return result;
    }

private:
    inline bool is_lower_letter(char c) {
        return (c >= 'a') && (c <= 'z');
    }

    inline void to_lower_letter(string &s) {
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            if ((s[i] >= 'A') && (s[i] <= 'Z'))
                s[i] = s[i] - 'A' + 'a'; 
        }
    }     
};
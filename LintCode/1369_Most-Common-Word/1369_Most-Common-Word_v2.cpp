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
        
        stringstream ss(paragraph);
        string buf;
        //vector<string> words;
        while(ss >> buf) {
            if (!is_lower_letter(buf.back())) buf.pop_back();
            
            if (s.find(buf) == s.end()) {
                if (mp.find(buf) == mp.end()) {
                    mp[buf] = 1;     
                } else {
                    mp[buf]++;
                }
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
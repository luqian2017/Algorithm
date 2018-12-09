class Solution {
public:
    /**
     * @param emails: Original email
     * @return: Return the count of groups which has more than one email address in it.
     */
    int countGroups(vector<string> &emails) {
        
        map<string, int> mp; //string, count
        for (auto email : emails) {
            string s;
            int len = email.size();
            bool foundPlus = false;
            bool foundAt = false;
            for (int i = 0; i < len; ++i) {
                if (email[i] == '+') {
                    foundPlus = true;
                    continue;
                }
                
                if (email[i] == '@') { 
                    foundAt = true;
                    foundPlus = false;
                }
                
                if (!foundAt) {
                    if (foundPlus) continue;
                    if (email[i] == '.') continue;
                    else {
                        s = s + email[i];  //     s[index++] = email[i];   //wrong!!!
                    }
                } else {
                    s = s + email[i];
                }
            }

            if (mp.find(s) == mp.end()) mp[s] = 1;
            else mp[s]++;
        }
        
        int count = 0;
        for (auto m : mp) {
            if (m.second > 1) count++;
        }
        
        return count;
    }
};
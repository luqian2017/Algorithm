class Solution {
public:
    /**
     * @param stringIn: The original string.
     * @param K: The length of substrings.
     * @return: return the count of substring of length K and exactly K distinct characters.
     */
    int KSubstring(string &stringIn, int K) {
        deque<char> dq;
        map<char, int> mp;   //char, count
        set<deque<char>> s;
        int len = stringIn.size();

        for (int i = 0; i < len; ++i) {
            if (dq.size() == K) {
                char c = dq.front();
                dq.pop_front();
                if (mp[c] == 1)
                    mp.erase(c);
                else 
                    mp[c]--;
            }    
            
            dq.push_back(stringIn[i]);   
            if (mp.find(stringIn[i]) == mp.end())
                mp[stringIn[i]] = 1;
            else
                mp[stringIn[i]]++;

            if ((dq.size() == K) && (mp.size() == K)) {
                s.insert(dq);
            }
        }
        
        return s.size();
    }
};
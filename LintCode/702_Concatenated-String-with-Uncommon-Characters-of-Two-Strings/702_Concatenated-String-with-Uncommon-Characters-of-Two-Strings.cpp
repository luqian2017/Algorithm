class Solution {
public:
    /**
     * @param s1: the 1st string
     * @param s2: the 2nd string
     * @return: uncommon characters of given strings
     */
    string concatenetedString(string &s1, string &s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        
        vector<int> set1(256), common(256);
        for (int i = 0; i < n1; ++i) {
            set1[s1[i]] = 1;
        }
        
        for (int i = 0; i < n2; ++i) {
            if (set1[s2[i]]) common[s2[i]] = 1;
        }
        
        string result;
        for (int i = 0; i < n1; ++i) {
            if (!common[s1[i]]) result += s1[i]; 
        }
        for (int i = 0; i < n2; ++i) {
            if (!common[s2[i]]) result += s2[i]; 
        }
        return result;
    }
};
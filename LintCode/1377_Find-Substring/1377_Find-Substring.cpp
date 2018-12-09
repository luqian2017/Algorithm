class Solution {
public:
    /**
     * @param str: The string
     * @param k: The length of the substring
     * @return: The answer
     */
    int findSubstring(string &str, int k) {
        int len = str.size();
        set<string> ss;
        int upperBound = len - k;
        
        for(int i = 0; i <= upperBound; ++i) {
            string sub_str = str.substr(i, k);
            if (check(sub_str)) {
                ss.insert(sub_str);
            }
        }
        
        return ss.size();
    }

private:
    bool check(string &str) {
        vector<bool> dup(26, false);
        int len = str.size();
        for (int i = 0; i < len; ++i) {
            int index = str[i] - 'a';
            if (dup[index]) return false;
            dup[index] = true;
        }
        return true;
    }
    
};
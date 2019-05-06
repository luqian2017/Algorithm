class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: if string A contains all of the characters in B return true else return false
     */
    bool compareStrings(string &A, string &B) {
        int m = A.size();
        int n = B.size();
        if (m == 0 && n == 0) return true;
        if (m < n) return false;

        unordered_map<char, int> us;   //<char, count>
        for (auto c : A) {
            if (us.find(c) == us.end()) {
                us[c] = 1;
            } else {
                us[c]++;
            }
        }
        
        for (auto c : B) {
            if (us.find(c) == us.end()) return false;
            us[c]--; 
            if (us[c] == 0) us.erase(c);
        }
        
        return true;
    }
};
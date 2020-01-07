class Solution {
public:
    /**
     * @param s: a string represent DNA sequences
     * @return: all the 10-letter-long sequences 
     */
    vector<string> findRepeatedDna(string &s) {
        int n = s.size();
        if (n < 10) return vector<string>();
        unordered_map<string, int> strMap;
        vector<string> result;
        
        for (int i = 10; i <= n; ++i) {
            string subString = s.substr(i - 10, 10);
            strMap[subString]++;
        }
        
        for (auto elem : strMap) {
            if (elem.second > 1) result.push_back(elem.first);
        }
        return result;
    }
};
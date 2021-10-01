class Solution {
public:
    /**
     * @param s: a string
     * @param excludewords: a dict
     * @return: the most frequent word
     */
    string frequentWord(string &s, unordered_set<string> &excludewords) {
        stringstream ss(s);
        string val;
        unordered_map<string, int> um;
        while (getline(ss, val, ',')) {
            stringstream ss2(val);
            string val2;
            while (ss2 >> val2) {
                if (excludewords.find(val2) == excludewords.end()) {
                    um[val2]++;
                }
            }
        }
        string res;
        int maxCount = 0;
        for (auto w : um) {
            if (w.second > maxCount) {
                maxCount = w.second;
                res = w.first;
            } else if (w.second == maxCount) {
                res = min(res, w.first);
            }
        }
     
        return res;
    }
};
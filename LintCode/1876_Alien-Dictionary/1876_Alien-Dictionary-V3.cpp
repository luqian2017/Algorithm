unordered_map<char, int> dict;
struct cmp {
    bool operator() (const string &a, const string &b) {
        int nSize = min(a.size(), b.size());
        for (int i = 0; i < nSize; ++i) {
            if (dict[a[i]] < dict[b[i]]) return true;
            if (dict[a[i]] > dict[b[i]]) return false;
        }
        if (a.size() <= b.size()) return true;
        else return false;
    }
};

class Solution {
public:
    /**
     * @param words: the array of string means the list of words
     * @param order: a string indicate the order of letters
     * @return: return true or false
     */
    bool isAlienSorted(vector<string> &words, string &order) {
        
        vector<string> words2(words);
        for (int i = 0; i < order.size(); i++) {
            dict[order[i]] = i;
        }
        sort(words2.begin(), words2.end(), cmp());
        return words == words2;
    }

};
unordered_map<char, int> dict;
bool compare (string &a, string &b) {
    int nSize = min(a.size(), b.size());
    for (int i = 0; i < nSize; ++i) {
        if (dict[a[i]] < dict[b[i]]) return true;
        else if (dict[a[i]] > dict[b[i]]) return false;
    }
    if (a.size() <= b.size()) return true;
    else return false;
}

class Solution {
public:
    /**
     * @param words: the array of string means the list of words
     * @param order: a string indicate the order of letters
     * @return: return true or false
     */
    bool isAlienSorted(vector<string> &words, string &order) {
        for (int i = 0; i < order.size(); i++) {
            dict[order[i]] = i;
        }
        for (int i = 0; i < words.size() - 1; i++) {
            if (!compare(words[i], words[i + 1])) return false;
        }
        return true;
    }

};
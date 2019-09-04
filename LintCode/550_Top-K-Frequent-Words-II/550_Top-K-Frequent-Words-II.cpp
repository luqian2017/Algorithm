
map<string, int> words;   //string vs frequent
struct cmp {
    bool operator() (const string & a, const string & b) {
        if (words[a] == words[b]) return a < b;
        return words[a] > words[b];
    }
};
    
class TopK {
public:
    /*
    * @param k: An integer
    */TopK(int k) {
        this->k = k;
    }

    /*
     * @param word: A string
     * @return: nothing
     */
    void add(string &word) {
        if (words.find(word) == words.end()) {
            words[word] = 1;
        } else {
            if (q.find(word) != q.end()) {
                q.erase(word);
            }
            words[word]++;
        }
        q.insert(word);
        if (q.size() > k) {
            q.erase(--q.end());
        }
    }

    /*
     * @return: the current top k frequent words.
     */
    vector<string> topk() {
        vector<string> result(q.begin(), q.end());
        return result;
    }

private:
    set<string, cmp> q;
    int k;
};
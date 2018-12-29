struct Node {
    string word;
    int count;
    Node(string w, int c) : word(w), count(c) {}
    bool operator < (const Node &n) const {
        return (count > n.count) || ((count == n.count) && (word < n.word)); 
    }
};

class Solution {
public:
    /**
     * @param words: an array of string
     * @param k: An integer
     * @return: an array of string
     */
    
    vector<string> topKFrequentWords(vector<string> &words, int k) {
        vector<string> result;
         
        map<string, int> mp; //word, freq
        int len = words.size();
        
        if ((len == 0) || (k == 0) || (len < k)) return result;
        for (int i = 0; i < len; ++i) {
            string w = words[i];
            if (mp.find(w) == mp.end()) {
                mp[w] = 1;
            } else {
                mp[w]++;
            }
        }
        
        vector<Node> vN;
        for (auto m : mp) {
            vN.push_back(Node(m.first, m.second));
        }
        sort(vN.begin(), vN.end());
        
        for (int i = 0; i < k; ++i) {
            result.push_back(vN[i].word);
        }
        return result;
    }
};

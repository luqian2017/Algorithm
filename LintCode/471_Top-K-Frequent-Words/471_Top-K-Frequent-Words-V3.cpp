struct Node {
    string str;
    int freq;
    Node(string s, int f) : str(s), freq(f) {}
    bool operator < (const Node & n) const {
        if (freq > n.freq) return true;
        if (freq == n.freq && str < n.str) return true;
        return false;
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
        
        int n = words.size();
        if (n == 0 || k == 0 || n < k) return {};

        priority_queue<Node> minHeap;
        map<string, int> hashmap;

        for (int i = 0; i < n; ++i) {
            hashmap[words[i]]++;
        }
        
        int validWordsCount = hashmap.size();

        for (auto w : hashmap) {
            Node node = Node(w.first, w.second);
            if (minHeap.size() < k) {
                minHeap.push(node);
            } else {
                if (node < minHeap.top()) {
                    minHeap.pop();
                    minHeap.push(node);
                }
            }
        }
        
        vector<string> result;
        while(!minHeap.empty()) {
            result.push_back(minHeap.top().str);
            minHeap.pop();
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
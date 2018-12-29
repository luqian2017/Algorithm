map<string, int> mp; //word, freq
struct cmp {
    bool operator () (const string & s1, const string & s2) {
        if (mp[s1] > mp[s2]) return true;
        if ((mp[s1] == mp[s2]) && (s1 < s2)) return true;
        return false;
    }
};
priority_queue<string, vector<string>, cmp> minHeap; 
        
class Solution {
public:
    /**
     * @param words: an array of string
     * @param k: An integer
     * @return: an array of string
     */
    
    vector<string> topKFrequentWords(vector<string> &words, int k) {
        vector<string> result;
        minHeap = priority_queue<string, vector<string>, cmp>();
        mp.clear();
         
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
        
        for (auto m : mp) {
            string w = m.first;
            if (minHeap.size() < k) { 
                minHeap.push(w);
            } else {
                if (((mp[w] > mp[minHeap.top()]) || ((mp[w] > mp[minHeap.top()]) && w < minHeap.top()))) {
                    minHeap.pop();
                    minHeap.push(w);
                }
            }
        }
        
        while(!minHeap.empty()) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};
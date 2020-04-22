
//bool operator < (const pair<int, int> & a, const pair<int, int> & b) {
//    if (a.first == b.first) return a.second > b.second;
//    return a.first < b.first;
//}

struct compare {
    bool operator () (const pair<int, int> & a, const pair<int, int> & b) {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }
}cmp;

class Solution {
public:
    /*
     * @param envelopes: a number of envelopes with widths and heights
     * @return: the maximum number of envelopes
     */
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int n = envelopes.size();
        if (n == 0) return 0;
        sort(envelopes.begin(), envelopes.end(), cmp);
        
        vector<int> monoIncSeqs;
        for (int i = 0; i < n; ++i) {
            vector<int>::iterator it = lower_bound(monoIncSeqs.begin(), monoIncSeqs.end(), envelopes[i].second);
            if (it == monoIncSeqs.end()) {
                monoIncSeqs.push_back(envelopes[i].second);
            } else {
                *it = envelopes[i].second;
            }
            
            //int k = binarySearch(monoIncSeqs, envelopes[i].second);
            //monoIncSeqs[k] = envelopes[i].second;
        }
        
        //for (int i = n - 1; i >= 0; --i) {
        //    if (monoIncSeqs[i] != INT_MAX) return i + 1;
        //}
        
        return monoIncSeqs.size();
    }
};

bool operator < (const pair<int, int> & a, const pair<int, int> & b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

class Solution {
public:
    /*
     * @param envelopes: a number of envelopes with widths and heights
     * @return: the maximum number of envelopes
     */
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int n = envelopes.size();
        if (n == 0) return 0;
        sort(envelopes.begin(), envelopes.end());for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[i].first > envelopes[j].first &&
                    envelopes[i].second > envelopes[j].second) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
            }
            gMaxLevel = max(gMaxLevel, dp[i]);
        }
        
        return gMaxLevel;
    }
};

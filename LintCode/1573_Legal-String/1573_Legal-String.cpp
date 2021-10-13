class Solution {
public:
    /**
     * @param k: The necessary distance of same kind of letters
     * @param S: The original string
     * @return: Return the number of '_' inserted before each position of the original string
     */
    vector<int> getAns(int k, string &S) {
        int n = S.size();
        if (n == 0) return {};
        vector<int> res;
        res.push_back(0);
        vector<int> latestPos(26, INT_MAX);
        latestPos[S[0] - 'A'] = 0;
        int cum_add_cnt = 0;
        for (int i = 1; i < n; ++i) {
            if (latestPos[S[i] - 'A'] < INT_MAX) {
                int dist = i + cum_add_cnt - latestPos[S[i] - 'A'];
                if (dist < k) {
                    res.push_back(k - dist);
                    cum_add_cnt += k - dist;
            //        latestPos[S[i] - 'A'] = i + cum_add_cnt;
                } else {
                    res.push_back(0);
            //        latestPos[S[i] - 'A'] = i + cum_add_cnt;
                }
            } else {
                res.push_back(0);
            //    latestPos[S[i] - 'A'] = i + cum_add_cnt;
            }
            latestPos[S[i] - 'A'] = i + cum_add_cnt;
            
        }
        return res;
    }
};
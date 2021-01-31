/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param A: An integer list
     * @param queries: An query list
     * @return: The result list
     */
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        int n = A.size();
        int m = queries.size();
        vector<long long> res(m, 0);
        vector<long long> presumes(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            presumes[i + 1] = presumes[i] + A[i];
        }
        
        for (int i = 0; i < m; ++i) {
            res[i] = presumes[queries[i].end + 1] - presumes[queries[i].start];
        }
        return res;
    }
};
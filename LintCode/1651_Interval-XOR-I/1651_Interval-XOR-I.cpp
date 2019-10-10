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
     * @param A: 
     * @param query: 
     * @return: nothing
     */
    vector<int> intervalXOR(vector<int> &A, vector<Interval> &query) {
        int m = A.size();
        if (m == 0) return vector<int>();
        vector<int> result;
        int n = query.size();
        for (int i = 0; i < n; ++i) {
            Interval itv = query[i];
            int ret = 0;
            for (int j = itv.start; j <= itv.start + itv.end - 1; ++j) {
                ret = ret ^ A[j];
            }
            result.push_back(ret);
        }
        return result;
    }
};
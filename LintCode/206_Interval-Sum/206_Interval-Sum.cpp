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
        len = A.size();
        C.resize(len + 1, 0);
        vector<long long> result;
        
        for (int i = 0; i < len; ++i) add(i, A[i]);

        int n = queries.size();
        for (int i = 0; i < n; ++i) {
            result.push_back(sum(queries[i].end) - sum(queries[i].start - 1));
        }    
        
        return result;
    }
private:
    vector<long long> C;
    int len;
    
    int lowbit(int x) {
        return x & (-x);
    }
    void add(int x, int val) {
        x++;
        for (int i = x; i <= len; i += lowbit(i)) {
            C[i] += val;
        }
    }
    
    long long sum(int x) {
        x++;
        long long result = 0;

        for (int i = x; i > 0; i -= lowbit(i)) {
            result += C[i];
        }
        return result;
    }
};
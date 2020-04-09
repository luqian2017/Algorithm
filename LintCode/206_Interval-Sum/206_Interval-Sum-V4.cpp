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

class BinaryIndexTree {
public:
    vector<int> C;
    int len;
    
    BinaryIndexTree(vector<int> &A) {
        len = A.size();
        C.resize(len + 1);
        for (int i = 0; i < len; ++i) {
            add(i, A[i]);
        }
    }
    
    void add(int index, int val) {
        index++;
        for (int i = index; i <= len; i += lowbit(i)) {
            C[i] += val;
        }
    }
    
    long long presum(int index) {
        index++;
        long long result = 0;
        for (int i = index; i > 0; i -= lowbit(i)) {
            result += C[i];
        }
        return result;
    }
    
private:
    int lowbit(int x) {
        return x & (-x);
    }
};
 
class Solution {
public:
    /**
     * @param A: An integer list
     * @param queries: An query list
     * @return: The result list
     */
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        vector<long long> result;
        BinaryIndexTree Bit(A);

        for (int i = 0; i < queries.size(); ++i) {
            result.push_back(Bit.presum(queries[i].end) - Bit.presum(queries[i].start - 1));
        }
        
        return result;
    }

};
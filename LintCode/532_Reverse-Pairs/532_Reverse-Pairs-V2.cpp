class Solution {
public:
    /**
     * @param A: an array
     * @return: total of reverse pairs
     */
    long long reversePairs(vector<int> &A) {
        vector<int> sortedA = A;
        sort(sortedA.begin(), sortedA.end());
        uniqLen = unique(sortedA.begin(), sortedA.end()) - sortedA.begin();
        C.resize(uniqLen + 1, 0);
        long long result = 0;

        //discrete A[]
        for (int i = 0; i < A.size(); ++i) {
            A[i] = lower_bound(sortedA.begin(), sortedA.begin() + uniqLen, A[i]) - sortedA.begin() + 1;
        }
        
        for (int i = 0; i < A.size(); ++i) {
            for (int j = A[i]; j <= uniqLen; ++j) {
                C[j]++;
            }
            result += C[uniqLen] - C[A[i]];
        }
        
        return result;
    }

private:
    int uniqLen;
    vector<int> C;
};
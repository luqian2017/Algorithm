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
            add(A[i], 1);
            result += sum(uniqLen) - sum(A[i]);
        }
        
        return result;
    }


private:
    int uniqLen;
    vector<int> C;
    
    int lowbit(int x) {
        return x & (-x);
    }
    
    int sum(int x) {
        int result = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            result += C[i];
        }
        return result;
    }
    
    void add(int x, int v) {
        for (int i = x; i <= uniqLen; i += lowbit(i)) {
            C[i] += v;
        }
    }
};
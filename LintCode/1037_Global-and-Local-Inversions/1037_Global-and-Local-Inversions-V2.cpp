class Solution {
public:
    /**
     * @param A: an array
     * @return: is the number of global inversions is equal to the number of local inversions
     */
    bool isIdealPermutation(vector<int> &A) {
        int n = A.size();
        if (n < 2) return true;
        C.resize(n + 1);
        int globalInvCount = 0, localInvCnt = 0;
        
        //calculate globalInvCount
        for (int i = 0; i < n; ++i) {
            add(A[i], n);
            globalInvCount += i + 1 - sum(A[i]);
        }
        
        //calculate localInvCnt
        for (int i = 1; i < n; ++i) {
            if (A[i - 1] > A[i]) localInvCnt++;
        }

        return globalInvCount == localInvCnt;
    }

private:
    vector<int> C;
    int lowbit(int x) {
        return x & (-x);
    }
    
    void add(int x, int n) {
        x++;
        for (int i = x; i <= n; i += lowbit(i)) C[i] += 1;
    }
    
    int sum(int x) {
        x++;
        int result = 0;
        for (int i = x; i > 0; i -= lowbit(i)) result += C[i];
        return result;
    }
};
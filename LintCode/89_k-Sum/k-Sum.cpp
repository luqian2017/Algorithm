class Solution {
public:
    /**
     * @param A: An integer array
     * @param k: A positive integer (k <= length(A))
     * @param target: An integer
     * @return: An integera
     */
    int kSum(vector<int> &A, int k, int target) {
        int n = A.size();
        if (n < k) return 0;
        vector<int> sol;
        sort(A.begin(), A.end());
        helper(A, k, target, 0, sol);
        
        return s.size();
    }

private:
    void helper(vector<int> &A, int k, int target, int index, vector<int> &sol) {
        if (k == 0) {
            if (target == 0) s.insert(sol);
            return;
        }
        
        int n = A.size();
        
        for (int i = index; i < n; ++i) {
            if (target < A[i]) return;
            sol.push_back(A[i]);
            helper(A, k - 1, target - A[i], i + 1, sol);
            sol.pop_back();
        }
        
    }
    
    set<vector<int>> s;
};
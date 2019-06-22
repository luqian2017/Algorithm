class Solution {
public:
    /*
     * @param A: an integer array
     * @param k: a postive integer <= length(A)
     * @param target: an integer
     * @return: A list of lists of integer
     */
    vector<vector<int>> kSumII(vector<int> &A, int k, int target) {
        sort(A.begin(), A.end());
        vector<int> sol;
        helper(A, sol, k, 0, target);
        return solutions;
    }

private:
    vector<vector<int>> solutions;
    
    void helper(vector<int> &A, vector<int> &sol, int k, int index, int target) {
        if (sol.size() == k && target == 0) {
            solutions.push_back(sol);
            return;
        }
        
        if (sol.size() >= k || target < 0) return;
        
        for (int i = index; i < A.size(); ++i) {
            if (A[i] > target) return;
            sol.push_back(A[i]);
            helper(A, sol, k, i + 1, target - A[i]);
            sol.pop_back();
        }
        
    }
};

class Solution {
public:
    /**
     * @param a: the array a
     * @param k: the integer k
     * @param target: the integer target
     * @return: return the number of legal schemes
     */
    int getAns(vector<int> &a, int k, int target) {
        count = 0;
        sort(a.begin(), a.end());
        vector<int> sol;
        helper(a, sol, k, 0, target, true);
        sol.clear();
        helper(a, sol, k, 0, target, false);
        return count;
    }

private:
    int count;
    void helper(vector<int> &A, vector<int> &sol, int k, int index, int target, bool isOdd) {
        if (sol.size() == k && target == 0) {
            count++;
            return;
        }
        
        if (target < 0) return;
        
        for (int i = index; i < A.size(); ++i) {
            if (isOdd && !(A[i] & 0x1)) continue;
            else if (!isOdd && (A[i] & 0x1)) continue;
            
            if (A[i] > target) return;
            
            sol.push_back(A[i]);
            helper(A, sol, k, i + 1, target - A[i], isOdd);
            sol.pop_back();
        }
    }
};

//some test cases
/*
[1,2,3,4]
4
1

[9,1,4,4]
3
46

[10,3,1,1]
3
5

[9,1,8,2,7,3,6,4]
2
10
*/
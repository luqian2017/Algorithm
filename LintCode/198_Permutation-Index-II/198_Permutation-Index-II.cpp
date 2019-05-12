class Solution {
public:
    /**
     * @param A: An array of integers
     * @return: A long integer
     */
    long long permutationIndexII(vector<int> &A) {
         int n = A.size();
        if (n <= 1) return n;
        long long result = 1, currFactorial = 1, multiFactorial = 1;
        unordered_map<int, int> um;
        for (int i = n - 1; i >= 0; --i) {
            int smallers = 0;
            um[A[i]]++;
            multiFactorial *= um[A[i]];
            for (int j = i + 1; j < n; ++j) {
                if (A[j] < A[i]) smallers++;
            }
            result += currFactorial * smallers / multiFactorial;
            currFactorial *= n - i;
        }
        
        return result;
    }
};
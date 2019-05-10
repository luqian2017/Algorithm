class Solution {
public:
    /**
     * @param A: An array of integers
     * @return: A long integer
     */
    long long permutationIndex(vector<int> &A) {
        int n = A.size();
        if (n <= 1) return n;
        long long result = 1;
        long long currFactorial = 1;
        for (int i = n - 2; i >= 0; --i) {
            int smallers = 0;
            for (int j = i + 1; j < n; ++j) {
                if (A[j] < A[i]) smallers++;
            }
            result += currFactorial * smallers;
            currFactorial *= n - i;
        }
        
        return result;
    }
};
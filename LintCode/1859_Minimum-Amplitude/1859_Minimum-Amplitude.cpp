class Solution {
public:
    /**
     * @param A: a list of integer
     * @return: Return the smallest amplitude
     */
    int MinimumAmplitude(vector<int> &A) {
        int n = A.size();
        if (n <= 4) return 0;
        sort(A.begin(), A.end());
        
        int option1 = A[n - 4] - A[0];
        int option2 = A[n - 3] - A[1];
        int option3 = A[n - 2] - A[2];
        int option4 = A[n - 1] - A[3];
        
        return min(option1, min(option2, min(option3, option4)));
    }
};
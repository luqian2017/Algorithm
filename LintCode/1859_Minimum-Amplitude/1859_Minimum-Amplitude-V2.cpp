class Solution {
public:
    /**
     * @param A: a list of integer
     * @return: Return the smallest amplitude
     */
    int MinimumAmplitude(vector<int> &A) {
        // write your code here
        int n = A.size();
        if(n <= 4) return 0;

        sort(A.begin(), A.end());
        
        int mmin = INT_MAX;
        for(int i = 0;i < 4;i++){
            mmin = min(mmin, A[n - 3 + i - 1] - A[i]);
        } 
        return mmin;
    }
};
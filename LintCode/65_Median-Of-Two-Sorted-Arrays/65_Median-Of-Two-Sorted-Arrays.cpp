class Solution {
public:
    /*
     * @param A: An integer array
     * @param B: An integer array
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
        int totalLen = A.size() + B.size();
        
        if (totalLen & 0x1) {
            return helper(A, 0, B, 0, totalLen / 2 + 1);
        } else {
            return helper(A, 0, B, 0, totalLen / 2) / 2.0 + helper(A, 0, B, 0, totalLen / 2 + 1) / 2.0;
        }
        
    }
    
private:
    int helper(vector<int> &A, int startA, vector<int> &B, int startB, int K) {
        if (startA >= A.size()) {
            return B[startB + K - 1];
        }
        
        if (startB >= B.size()) {
            return A[startA + K - 1];
        }
        
        if (K == 1) {
            return min(A[startA], B[startB]);
        }
        
        int halfKofA = 0, halfKofB = 0; 
    
        if ((startA + K / 2) > A.size()) {
            halfKofA = INT_MAX;
        } else {
            halfKofA = A[startA + K / 2 - 1];
        }
        
        if ((startB + K / 2) > B.size()) {
            halfKofB = INT_MAX;
        } else {
            halfKofB = B[startB + K / 2 - 1];
        }
        
        if (halfKofA > halfKofB) {
            // should be in the other k/2 of B
            return helper(A, startA, B, startB + K / 2, K - K / 2);
            //return helper(A, startA, B, startB + K / 2, K / 2);
        } else {
            // should be in the other k/2 of a
            return helper(A, startA + K / 2, B, startB, K - K / 2 );
            //return helper(A, startA + K / 2, B, startB, K / 2 );
        }
    }

};
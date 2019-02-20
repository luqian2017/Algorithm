class Solution {
public:
    /*
     * @param A: An integer matrix
     * @return: The index of the peak
     */
    vector<int> findPeakII(vector<vector<int>> &A) {
        int nRow = A.size();
        int nCol = A[0].size();
        vector<int> res;
        int rMin = 0, rMax = nRow - 1;
        
        while(rMin + 1 < rMax) {
            int rMid = rMin + (rMax - rMin) / 2;
            int index = findPeakInRow(A, rMid);
            if (A[rMid][index] < A[rMid - 1][index]) {
                rMax = rMid;
            } else if (A[rMid][index] < A[rMid + 1][index]) {
                rMin = rMid;
            } else {
                return vector<int>{rMid, index};
            }
        }
    
        int rMaxIndex = findPeakInRow(A, rMax);
        int rMinIndex = findPeakInRow(A, rMin);
        if (A[rMin][rMinIndex] < A[rMax][rMaxIndex])
            return vector<int>{rMax, rMaxIndex};
        else
            return vector<int>{rMin, rMinIndex};
    }

private:
    int findPeakInRow(vector<vector<int>>& A, int row) {
        int col = 0;
        int len = A[0].size();
        for (int i = 1; i < len; ++i) {
            if (A[row][col] < A[row][i]) col = i;
        }
        return col;
    }
};
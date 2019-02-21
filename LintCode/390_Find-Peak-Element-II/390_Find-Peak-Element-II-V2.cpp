class Solution {
public:
    /*
     * @param A: An integer matrix
     * @return: The index of the peak
     */
    vector<int> findPeakII(vector<vector<int>> &A) {
        int nRow = A.size();
        int nCol = A[0].size();
        return find(A, 1, nRow - 2, 1, nCol - 2);
    }

private:
    vector<int> find(vector<vector<int>>& A, int rStart, int rEnd, int cStart, int cEnd) {
        int rMid = rStart + (rEnd - rStart) / 2;
        int cMid = cStart + (cEnd - cStart) / 2;
        
        int r = rMid, c = cMid;
        int maxV = A[rMid][cMid];
        
        for (int i = rStart; i <= rEnd; ++i) {
            if (A[i][cMid] > maxV) {
                maxV = A[i][cMid];
                r = i;
                c = cMid;
            }
        }
        
        for (int i = cStart; i <= cEnd; ++i) {
            if (A[rMid][i] > maxV) {
                maxV = A[rMid][i];
                r = rMid;
                c = i;
            }
        }
        
        
        if (A[r - 1][c] > A[r][c]) {
            r -= 1;
        } else if (A[r + 1][c] > A[r][c]) {
            r += 1;
        } else if (A[r][c - 1] > A[r][c]) {
            c -= 1;
        } else if (A[r][c + 1] > A[r][c]) {
            c += 1;
        } else {
            // it is peak
            return vector<int>{r, c};
        }
        
        if (r >= rStart && r < rMid && c >= cStart && c < cMid) {
            return find(A, rStart, rMid - 1, cStart, cMid - 1);
        }
        
        if (r >= rStart && r < rMid && c > cMid && c <= cEnd) {
            return find(A, rStart, rMid - 1, cMid + 1, cEnd);
        }
        
        if (r > rMid && r <= rEnd && c >= cStart && c < cMid) {
            return find(A, rMid + 1, rEnd, cStart, cMid - 1);
        }
        
        if (r > rMid && r <= rEnd && c > cMid && c <= cEnd) {
            return find(A, rMid + 1, rEnd, cMid + 1, cEnd);
        }
        
        return vector<int>();
    }
};
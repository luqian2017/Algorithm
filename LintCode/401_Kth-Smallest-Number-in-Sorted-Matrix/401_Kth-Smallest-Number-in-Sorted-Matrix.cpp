class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: An integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        
        priority_queue<int> pq;
        int nRow = matrix.size();
        int nCol = matrix[0].size();
        
        for (int i = 0; i < nRow; ++i) {
            for (int j = 0; j < nCol; ++j) {
                pq.push(matrix[i][j]);
                if (pq.size() > k) pq.pop();
            }
        }
        
        return pq.top();
    }
};
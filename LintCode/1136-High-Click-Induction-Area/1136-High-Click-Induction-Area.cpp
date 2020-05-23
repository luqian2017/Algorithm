struct Node {
    int row;
    int col;
    Node(int r = 0, int c = 0) : row(r), col(c) {}
};

class Solution {
public:
    /**
     * @param matrix: a two-dimensional matrix.
     * @param pixelThreshold: the pixel threshold judging high click position.
     * @param areaThreshold: the pixed threshold judging high click area.
     * @return: return the number of high click areas.
     */
    int highClickAreaCount(vector<vector<int>> &matrix, int pixelThreshold, int areaThreshold) {
        int nRow = matrix.size();
        if (nRow == 0) return 0;
        int nCol = matrix[0].size();
        if (nCol == 0) return 0;

	    int count = 0;
	    
        for (int i = 0; i < nRow; ++i) {
            for (int j = 0; j < nCol; ++j) {
                int islandSize = 0;
                if (matrix[i][j] > pixelThreshold) {
                    islandSize = bfs(matrix, i, j, pixelThreshold);
                    if (islandSize > areaThreshold) {
                        count++;
                    }
                }
            }
        }
            
        return count;
    }

private:
    int bfs(vector<vector<int>> &matrix, int row, int col, int pixelThreshold) {
        int nRow = matrix.size();
        int nCol = matrix[0].size();
        int islandSize = 1;
        queue<Node> q; 
        
        int dx[4] = {1, 0, -1, 0};
	    int dy[4] = {0, 1, 0, -1};
	    
        q.push(Node(row, col));
        matrix[row][col] = -1;
        
        while(!q.empty()) {
            Node currNode = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int newRow = currNode.row + dx[k];
                int newCol = currNode.col + dy[k];
                if (newRow >= 0 && newRow < nRow && newCol >= 0 && newCol < nCol && matrix[newRow][newCol] > pixelThreshold) {
                    matrix[newRow][newCol] = -1;
                    q.push(Node(newRow, newCol));
                    islandSize++;
                }
            }
        }
        return islandSize;
        
        
    }
};
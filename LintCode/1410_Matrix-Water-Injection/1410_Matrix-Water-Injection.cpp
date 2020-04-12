class Solution {
public:
    /**
     * @param matrix: the height matrix
     * @param R: the row of (R,C)
     * @param C: the columns of (R,C)
     * @return: Whether the water can flow outside
     */
    string waterInjection(vector<vector<int>> &matrix, int R, int C) {
        int nRow = matrix.size();
        if (nRow == 0) return "NO";
        int nCol = matrix[0].size();
        queue<pair<int,int>> q;
        
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        
        q.push({R, C});
        
        while(!q.empty()) {
            pair<int, int> frontNode = q.front();
            q.pop();
            if (frontNode.first == nRow - 1 || frontNode.second == nCol - 1) return "YES";
            for (int i = 0; i < 4; ++i) {
                int newX = frontNode.first + dx[i];
                int newY = frontNode.second + dy[i];
                if (newX >= 0 && newX < nRow && newY >= 0 && newY < nCol) {
                    if (matrix[newX][newY] < matrix[frontNode.first][frontNode.second]) {
                        q.push({newX, newY});
                    }
                }
            }
        }
        
        return "NO";
    }
};
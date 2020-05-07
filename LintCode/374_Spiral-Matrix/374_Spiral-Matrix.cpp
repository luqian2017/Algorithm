class Solution {
public:
    /**
     * @param matrix: a matrix of m x n elements
     * @return: an integer list
     */
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int m = matrix.size();
        if (m == 0) return {};
        int n = matrix[0].size();
        if (n == 0) return {};
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        
        pair<int, int> node = {0, 0};
        int currDir = 0;
        vector<int> result;
        result.push_back(matrix[0][0]);
        visited[0][0] = 1;
        int cnt = 1;
        int totalCnt = m * n;
        
        while (cnt < totalCnt) {

            int newX = node.first + dx[currDir];
            int newY = node.second + dy[currDir];
            if (newX >= 0 && newX < m && newY >= 0 && newY < n && !visited[newX][newY]) {
                node = {newX, newY};
                result.push_back(matrix[newX][newY]);
                visited[newX][newY] = 1;
                cnt++;
            } else {
                currDir = (currDir + 1) % 4;
            }
        }
        
        return result;
    }
};
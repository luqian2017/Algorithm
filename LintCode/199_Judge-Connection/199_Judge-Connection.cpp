class Solution {
public:
    /**
     * @param arr: the arr
     * @param k: the k
     * @return: if all instances of value k in arr are connected
     */
        bool judgeConnection(vector<vector<int>> &arr, int k) {
        int nRow = arr.size();
        if (nRow == 0) return false;
        int nCol = arr[0].size();
        if (nCol == 0) return false;
        vector<vector<bool>> visited(nRow, vector<bool>(nCol, false));
        int numK = 0;
        int startX = 0, startY = 0;
        for (int i = 0; i < nRow; ++i) {
            for (int j = 0; j < nCol; ++j) {
                if (arr[i][j] == k) {
                    numK++;
                    startX = i; startY = j;
                }
            }
        }
        visited[startX][startY] = true;
        if (numK == 0) return false;
        
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        
        int countK = 0;
        queue<pair<int, int>> q;
        q.push({startX, startY});
        countK = 1;

        while(!q.empty()) {
            auto curNode = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int newX = curNode.first + dx[i];
                int newY = curNode.second + dy[i];

                if (newX < 0 || newX >= nRow || newY < 0 || newY >= nCol || visited[newX][newY] || arr[newX][newY] != k) continue;
                   visited[newX][newY] = true;
                   countK++;
                   q.push({newX, newY});
            }
        }

        if (countK == numK) return true;
        return false;
    }
};
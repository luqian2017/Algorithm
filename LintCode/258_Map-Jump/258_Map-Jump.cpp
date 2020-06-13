class Solution {
public:
    /**
     * @param arr: the map
     * @return:  the smallest target that satisfies from the upper left corner (0, 0) to the lower right corner (n-1, n-1)
     */
    int mapJump(vector<vector<int>> &arr) {
        int m = arr.size();
        int n = arr[0].size();
        int maxV = INT_MIN;
        int minV = INT_MAX;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (maxV < arr[i][j]) maxV = arr[i][j];
                if (minV > arr[i][j]) minV = arr[i][j];
            }
        }
        
        int start = 0, end = maxV - minV;
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (bfs(arr, mid)) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if (bfs(arr, start)) return start;
        else return end;
    }

private:
    bool bfs(vector<vector<int>> &arr, int threshold) {
        int m = arr.size();
        int n = arr[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = 1;
        
        while(!q.empty()) {
            auto curNode = q.front();
            q.pop();
            if (curNode.first == m - 1 && curNode.second == n - 1) return true;
           
            for (int i = 0; i < 4; ++i) {
                int newX = curNode.first + dx[i];
                int newY = curNode.second + dy[i];
                
                if (newX < 0 || newX >= m || newY < 0 || newY >= n || visited[newX][newY] || 
                     abs(arr[newX][newY] - arr[curNode.first][curNode.second]) > threshold) continue;
                q.push({newX, newY});
                visited[newX][newY] = 1;
            }
        }
        
        return false;
    }
};
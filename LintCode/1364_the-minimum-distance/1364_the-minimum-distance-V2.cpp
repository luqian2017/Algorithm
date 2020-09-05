class Solution {
public:
    /**
     * @param mazeMap: a 2D grid
     * @return: return the minium distance
     */
    int getMinDistance(vector<vector<int>> &mazeMap) {
        int num_row = mazeMap.size();
        int num_col = mazeMap[0].size();
        vector<vector<int>> visited(num_row, vector<int>(num_col, false));
        
        vector<bool> visited_fast_door(51, false); //if the fast door number is used.
        vector<vector<pair<int, int>>> fast_door(51); //each entry records the list of doors (row, col) that have the number i
        
        queue<pair<int, int>> q;
        pair<int, int> source, destination;

        for (int i = 0; i < num_row; ++i) {
            for (int j = 0; j < num_col; ++j) {
                if (mazeMap[i][j] == -2) {
                    source = {i, j};
                 } else if (mazeMap[i][j] == -3) {
                    destination = {i, j};
                 } else if (mazeMap[i][j] > 0) {
                    fast_door[mazeMap[i][j]].push_back({i, j});
                    visited_fast_door[mazeMap[i][j]] = false;
                }
            }
        }
        int steps = 0;
        q.push(source);
        visited[source.first][source.second] = true;
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        while(!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; ++i) {
                auto front = q.front();
                q.pop();
                int x = front.first;
                int y = front.second;
                int index = mazeMap[x][y];

                if (front == destination) {
                    return steps;
                }
                for (int j = 0; j < 4; ++j) {
                    int newX = front.first + dx[j];
                    int newY = front.second + dy[j];
                    if (newX < 0 || 
                        newX >= num_row || 
                        newY < 0 || 
                        newY >= num_col || 
                        visited[newX][newY] ||
                        mazeMap[newX][newY] == -1) {
                            continue;
                    } else {
                        q.push({newX, newY});
                        visited[newX][newY] = true;
                    }
                }

                //the 5th dimension, check if it is fast door
                if (index > 0) {
                    if (visited_fast_door[index]) {
                        continue;
                    } else {
                        for (int i = 0; i < fast_door[index].size(); ++i) {
                            int newX = fast_door[index][i].first;
                            int newY = fast_door[index][i].second;
                            if (visited[newX][newY]) continue;
                            visited[newX][newY] = 1;
                            q.push(fast_door[index][i]);
                        }
                        visited_fast_door[index] = true;
                    }
                }
            }
            steps++;

        }
        
        return -1;
    }
};
class Solution {
public:
    /**
     * @param side_length: the length of a side of the lake (it's a square)
     * @param lake_grid: a 2D matrix representing the lake 0= ice, 1= snowbank, -1= hole 
     * @param albert_row: row of Albert's snowbank
     * @param albert_column: column of Albert's snowbank 
     * @param kuna_row: row of Kuna's snowbank 
     * @param kuna_column: column of Kuna's snowbank
     * @return: a bool - whether Albert can escape
     */
    bool lakeEscape(int side_length, vector<vector<int>> &lake_grid, int albert_row, int albert_column, int kuna_row, int kuna_column) {
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        queue<pair<int, pair<int, int>>> q; //find_dog, <x, y>
        q.push({0, {albert_row, albert_column}});
        vector<vector<vector<int>>> visit(2, vector<vector<int>>(side_length, vector<int>(side_length, 0)));
        
        bool find_dog_flag = false;
        while(!q.empty()) {
            auto curNode = q.front();
            q.pop();
            if (visit[curNode.first][curNode.second.first][curNode.second.second]) continue;
            visit[curNode.first][curNode.second.first][curNode.second.second] = 1;

            for (int i = 0; i < 4; ++i) {
             //   bool isHole = false;
                bool outBound = false;
                bool isSnowBank = false;

                int newX = curNode.second.first;
                int newY = curNode.second.second;
                
                //keep sliding
                for (int j = 0; j <= side_length; ++j) {
                    newX += dx[i];
                    newY += dy[i];
                    
                    if (!find_dog_flag) {
                        if (newX == kuna_row && newY == kuna_column) {
                            find_dog_flag = true;   
                        }
                    }

                    if (newX < 0 || newX >= side_length || newY < 0 || newY >= side_length) {
                        outBound = true;
                        break;
                    }
                    
                    if (lake_grid[newX][newY] == -1) {
               //         isHole = true;
                        break;
                    }
                    
                    if (lake_grid[newX][newY] == 1) {
                        isSnowBank = true;
                        break; //bump into snowbank
                    }
                }
                
                if (outBound) {
                    if (find_dog_flag ) return true;
                } else if (isSnowBank) {
                    q.push({find_dog_flag, {newX, newY}});
                }
            }
        }
        return false;
    }
};
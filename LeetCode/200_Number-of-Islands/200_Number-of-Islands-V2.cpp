class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n_row = grid.size();
        int n_col = grid[0].size();
        father.resize(n_row * n_col + 1);
        //initialize, each node's father is itself
        for (int i = 0; i < n_row; i++) {
            for (int j = 0; j < n_col; j++) {
                int num = i * n_col + j;
                father[num] = num;
                if (grid[i][j] == '1') ans++;
            }
        }

       // vector<int> dx = {1, 0};
       // vector<int> dy = {0, 1};
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        
        for (int i = 0; i < n_row; i++) {
            for (int j = 0; j < n_col; j++) {
                if (grid[i][j] == '1') {
                    for (int k = 0; k < 4; k++) {
                        int newX = i + dx[k];
                        int newY = j + dy[k];
                        if (newX >= 0 && newX < n_row && 
                            newY >= 0 && newY < n_col &&
                            grid[newX][newY] == '1') {
                            join(i * n_col + j, newX * n_col + newY);
                        }
                    }               
                }
            }
        }
        
        return ans;        
    }

private:
    vector<int> father;
    int ans = 0;
    
    int find(int x) {
       if (father[x] == x) {
           return x;
       }
        return father[x] = find(father[x]);
    }
    
    void join(int x, int y) {
        int fatherX = find(x);
        int fatherY = find(y);
        if (fatherX != fatherY) {
            father[fatherX] = fatherY;
            ans--;
        }
    }
};







/*
Note: only two directsions are also OK!

  int numIslands(vector<vector<char>>& grid) {
        int n_row = grid.size();
        int n_col = grid[0].size();
        father.resize(n_row * n_col + 1);
        //initialize, each node's father is itself
        for (int i = 0; i < n_row; i++) {
            for (int j = 0; j < n_col; j++) {
                int num = i * n_col + j;
                father[num] = num;
                if (grid[i][j] == '1') ans++;
            }
        }

        vector<int> dx = {1, 0};
        vector<int> dy = {0, 1};
       // vector<int> dx = {0, 0, 1, -1};
       // vector<int> dy = {1, -1, 0, 0};
        
        for (int i = 0; i < n_row; i++) {
            for (int j = 0; j < n_col; j++) {
                if (grid[i][j] == '1') {
                    for (int k = 0; k < 2; k++) {
                        int newX = i + dx[k];
                        int newY = j + dy[k];
                        if (newX >= 0 && newX < n_row && 
                            newY >= 0 && newY < n_col &&
                            grid[newX][newY] == '1') {
                            join(i * n_col + j, newX * n_col + newY);
                        }
                    }               
                }
            }
        }
        
        return ans;        
    }
*/

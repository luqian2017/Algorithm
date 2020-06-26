class Solution {
public:
    /**
     * @param grid: an integer matrix
     * @return: an integer 
     */
    int numIslandCities(vector<vector<int>> &grid) {
          int m = grid.size();
          int n = grid[0].size();
          father.resize(m * n);
          hasCity.resize(m * n);
          
          // initialize
          for (int i = 0; i < m; ++i) {
              for (int j = 0; j < n; ++j) {
                  father[i * m + j] = i * m + j;
                  hasCity[i * m + j] = grid[i][j] == 2 ? true : false;
                  if (grid[i][j] == 2) count++;
              }
          }
          
          //union-find
          for (int i = 0; i < m; ++i) {
              for (int j = 0; j < n; ++j) {
                  if (grid[i][j] != 0) {
                      if (i + 1 >= 0 && i + 1 < m && j >= 0 && j < n && grid[i + 1][j] != 0) {
                          add(i * m + j, (i + 1) * m + j);
                      }
                      
                       if (i >= 0 && i < m && j + 1 >= 0 && j + 1 < n && grid[i][j + 1] != 0) {
                          add(i * m + j, i * m + j + 1);
                      }
                  }
              }
          }
          
          return count;
    }
    
private:
    vector<int> father;
    vector<bool> hasCity;
    int count = 0;
    
    int find(int x) {
        if (father[x] == x) return x;
        return father[x] = find(father[x]);
    }
    
    void add(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);
        if (root_a != root_b) {
            father[root_a] = root_b;
            if (hasCity[root_a] && hasCity[root_b]) count--;
            if (hasCity[a] || hasCity[b]) {
                hasCity[a] = hasCity[b] = true;
            }
        }
    }
};
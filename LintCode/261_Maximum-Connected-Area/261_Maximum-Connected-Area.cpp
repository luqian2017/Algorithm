class Solution {
public:
    /**
     * @param matrix: the matrix for calculation.
     * @return: return the max area after operation at most once.
     */
    int maxArea(vector<vector<int>> &matrix) {
          int result = 0;
          int m = matrix.size();
          int n = matrix[0].size();
          father.resize(m * n);
          area.resize(m * n);
          
          // initialize
          for (int i = 0; i < m; ++i) {
              for (int j = 0; j < n; ++j) {
                  if (matrix[i][j] != 0) {
                      father[i * n + j] = i * n + j;
                      area[i * n + j] = 1;
                      non_zero_count++;
                  }
              }
          }

          if (non_zero_count == m * n) {
              return non_zero_count;
          }
          
          //union-find
          for (int i = 0; i < m; ++i) {
              for (int j = 0; j < n; ++j) {
                  if (matrix[i][j] != 0) {
                      
                      for (int k = 0; k < 4; ++k) {
                          int newX = i + dx[k];
                          int newY = j + dy[k];
                          if (newX >= 0 && newX < m && newY >= 0 && newY < n && matrix[newX][newY] != 0) {
                              add(i * n + j, newX * n + newY);
                          }
                      }
                  }
              }
          }

          // go thru the matrix's 0
          for (int i = 0; i < m; ++i) {
              for (int j = 0; j < n; ++j) {
                  if (matrix[i][j] == 0) {
                      int count = 1; 
                      set<int> roots;
                      for (int k = 0; k < 4; ++k) {
                          int newX = i + dx[k];
                          int newY = j + dy[k];
                          if (newX >= 0 && newX < m && newY >= 0 && newY < n && matrix[newX][newY] != 0) {
                              int newRoot = find(newX * n + newY);
                              if (area[newX * n + newY] > 0 && roots.find(newRoot) == roots.end()) {
                                  roots.insert(newRoot);
                                  count += area[newRoot];
                              }
                          }
                      }
                      result = max(result, count);
                  }
              }
          }
          
          return result;
    }
private:
    vector<int> father;
    vector<int> area;
    int count = 0;
    int non_zero_count = 0;
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    
    int find(int x) {
        if (father[x] == x) return x;
        return father[x] = find(father[x]);
    }
    
    void add(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);
        if (root_a != root_b) {
            father[root_a] = root_b;
            area[root_b] += area[root_a];
        }
    }
};
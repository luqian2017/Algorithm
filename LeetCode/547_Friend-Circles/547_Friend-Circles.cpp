class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        if (n == 0) return 0;
        ans = n;
        father.resize(n);

        for (int i = 0; i < n; ++i) {
                father[i] = i;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (M[i][j] == 1) {
                    join(i, j);
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
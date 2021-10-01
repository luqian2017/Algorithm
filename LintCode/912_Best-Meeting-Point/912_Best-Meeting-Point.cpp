class Solution {
public:
    /**
     * @param grid: a 2D grid
     * @return: the minimize travel distance
     */
    int minTotalDistance(vector<vector<int>> &grid) {
        int nRow = grid.size();
        int nCol = grid[0].size();
        vector<int> xs, ys;
        int res = 0;
        for (int i = 0; i < nRow; i++) {
            for (int j = 0; j < nCol; j++) {
                if (grid[i][j]) {
                    xs.push_back(i);
                    ys.push_back(j);
                }
            }
        }
       // sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());
        res += calDist(xs);
        res += calDist(ys);
        return res;
    }

private:
    int calDist(const vector<int> &arr) {
        int n = arr.size();
        int res = 0;
        int start = 0, end = n - 1;
        while (start < end) {
            res += arr[end--] - arr[start++];
        }
        return res;
    }
};
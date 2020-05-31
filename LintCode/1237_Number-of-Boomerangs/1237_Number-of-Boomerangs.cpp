class Solution {
public:
    /**
     * @param points: a 2D array
     * @return: the number of boomerangs
     */
    int numberOfBoomerangs(vector<vector<int>> &points) {
        int n = points.size();
        if (n == 0) return 0;
        int res = 0;

        for (int i = 0; i < n; ++i) {
            unordered_map<int, int> dist; //dist, count of the dist
            for (int j = 0; j < n; ++j) {
                int xGap = points[i][0] - points[j][0];
                int yGap = points[i][1] - points[j][1];
                dist[xGap * xGap + yGap * yGap]++;
            }
            for (auto d : dist) {
                res += d.second * (d.second - 1);
            }
        }

        return res;
    }
};
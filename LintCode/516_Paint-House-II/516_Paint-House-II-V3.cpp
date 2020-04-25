class Solution {
public:
    /**
     * @param costs: n x k cost matrix
     * @return: an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>> &costs) {
        int n = costs.size();
        if (n == 0) return 0;
        int colors = costs[0].size();
        if (colors <= 1) return 0;

        int min1_id = 0, min1_v = costs[0][0];
        int min2_id = 1, min2_v = costs[0][1];
        
        if (costs[0][0] > costs[0][1]) {
            min1_id = 1; min1_v = costs[0][1];
            min2_id = 0; min2_v = costs[0][0];
        }

        for (int i = 2; i < colors; ++i) {
            if (costs[0][i] < costs[0][min1_id]) {
                min2_id = min1_id; min2_v = min1_v;
                min1_id = i; min1_v = costs[0][i];
            } else if (costs[0][i] < costs[0][min2_id]) {
                min2_id = i; min2_v = costs[0][i];
            }
        }

        for (int i = 1; i < n; ++i) {
            int last1_id = min1_id, last1_v = min1_v;
            int last2_id = min2_id, last2_v = min2_v;
            min1_id = -1; min2_id = -1;
            for (int j = 0; j < colors; ++j) {
                int curr_v;
                if (j == last1_id) {
                    curr_v = last2_v + costs[i][j];
                } else {
                    curr_v = last1_v + costs[i][j];
                }
                if (min1_id < 0 || curr_v < min1_v) {
                    min2_id = min1_id; min2_v = min1_v;
                    min1_id = j; min1_v = curr_v;
                } else if (min2_id < 0 || curr_v < min2_v) {
                    min2_id = j;
                    min2_v = curr_v;
                }
            }
        }

        return min1_v;
    }
};
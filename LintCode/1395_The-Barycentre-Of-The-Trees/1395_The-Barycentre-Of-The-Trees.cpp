class Solution {
public:
    /**
     * @param x: The vertexes of the edges
     * @param y: The vertexes of the edges
     * @return: Return the index of barycentre
     */
    int getBarycentre(vector<int> &x, vector<int> &y) {
        if (x.size() == 0) return 0;
        n = x.size() + 1;
        tree.resize(n + 1, vector<int>());  //same as tree.resize(n + 1)
        dp.resize(n + 1); //dp[i] is the the sum of the children nodes under the tree with root i plus 1, dp[i] = sum(dp[j]) + 1;
        
        for (int i = 0; i < x.size(); ++i) {
            tree[x[i]].push_back(y[i]);
            tree[y[i]].push_back(x[i]);
        }
        dfs(1, 0); //choose 1 as the root
        return gChosenNode;
    }
    
private:
    vector<vector<int>> tree;
    vector<int> dp;
    int gMaxSubTreeSize = INT_MAX;
    int gChosenNode = 0;
    int n;
    void dfs(int node, int father) {
        int maxSubTreeSize = 0;
        if (tree[node].size() == 0) {
            dp[node] = 1; //leave node
        } else {
            for (int i = 0; i < tree[node].size(); ++i) {
                int childNode = tree[node][i];
                if ( childNode != father) { // prevent endless loop
                    dfs(childNode, node);
                    dp[node] += dp[childNode];
                    maxSubTreeSize = max(maxSubTreeSize, dp[childNode]);
                }
            }
            dp[node] += 1; // add itself
        }
        maxSubTreeSize = max(maxSubTreeSize, n - dp[node]);
        if (maxSubTreeSize < gMaxSubTreeSize || (maxSubTreeSize == gMaxSubTreeSize && node < gChosenNode)) {
            gMaxSubTreeSize = maxSubTreeSize;
            gChosenNode = node;
        }
    }
};
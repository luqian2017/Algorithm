class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        priority_queue<int> maxHeap;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int candidate = matrix[i][j];
                if (count < k) {
                    maxHeap.push(candidate);
                }
                else if (candidate < maxHeap.top()) {
                    maxHeap.push(candidate);
                    maxHeap.pop();
                }
                count++;
            }
        }
        return maxHeap.top();
    }
};
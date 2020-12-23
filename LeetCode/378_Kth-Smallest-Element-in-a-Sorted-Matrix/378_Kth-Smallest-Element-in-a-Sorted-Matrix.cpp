class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        priority_queue<int> maxHeap;
        vector<int> pos(n, 0);
        int count = 0, total_count = m * n;
        while (count < total_count) {
            for (int i = 0; i < n; ++i) {
                int candidate = matrix[i][pos[i]];
                if (count < k) {
                    maxHeap.push(candidate);
                    pos[i]++;
                }
                else if (candidate < maxHeap.top()) {
                    maxHeap.push(candidate);
                    maxHeap.pop();
                    pos[i]++;
                }
                count++;
            }
        }
        return maxHeap.top();
    }
};
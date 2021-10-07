struct ResultType {
    int val;
    int row;
    int col;
    ResultType(int v, int r, int c) : val(v), row(r), col(c) {}
    bool operator < (const ResultType & a) const {
        return val > a.val;
    }
};

class Solution {
public:
    /**
     * @param arr: an array of integers
     * @param k: an integer
     * @return: the Kth smallest element in a specific array
     */
    int kthSmallest(vector<vector<int>> &arr, int k) {
        int nRow = arr.size();
        int nCol = arr[0].size();
        priority_queue<ResultType> minHeap;
        int cnt = 0;
        for (int i = 0; i < nRow; i++) {
            if (!arr[i].empty()) minHeap.push({arr[i][0], i, 0});
        }
        while (!minHeap.empty()) {
            cnt++;
            ResultType topNode = minHeap.top();
            minHeap.pop();
            if (cnt == k) return topNode.val;
            if (topNode.col < arr[topNode.row].size() - 1) {
                minHeap.push({arr[topNode.row][topNode.col + 1], topNode.row, topNode.col + 1});
            } 
        }
        return -1;
    }
};
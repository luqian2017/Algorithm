class Node {
public:
    Node(int r, int c, int v) : row(r), col(c), val(v) {}
    //min-heap
    bool operator < (const Node & obj) const {
        return val > obj.val;
    }
    int row, col, val;
};

class Solution {
public:
    /**
     * @param arrays: k sorted integer arrays
     * @return: a sorted array
     */
    vector<int> mergekSortedArrays(vector<vector<int>> &arrays) {
        vector<int> result;
        int nRow = arrays.size();
        if (nRow == 0) return result;
        int nCol = arrays[0].size();
        
        priority_queue<Node> pq;
        
        for (int i = 0; i < nRow; ++i) {
            if (arrays[i].size() > 0) pq.push(Node(i, 0, arrays[i][0]));
        }
        
        while(!pq.empty()) {
            Node currTop = pq.top();
            pq.pop();
            result.push_back(currTop.val);
            if (currTop.col + 1 < arrays[currTop.row].size()) {
                pq.push(Node(currTop.row, currTop.col + 1, arrays[currTop.row][currTop.col + 1]));
            }
        }
        
        return result;
    }
};
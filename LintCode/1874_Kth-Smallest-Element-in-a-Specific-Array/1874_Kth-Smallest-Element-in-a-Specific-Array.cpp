struct Node {
    int x;
    int y;
    int v;
    Node(int _x = 0, int _y = 0, int _v = 0) : x(_x), y(_y), v(_v) {}
    bool operator < (const Node & a) const {
        return v > a.v;
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
        int rowNum = arr.size();
        priority_queue<Node> pq;
        
        for (int i = 0; i < rowNum; ++i) {
            if (arr[i].size() > 0) {
                pq.push(Node(i, 0, arr[i][0]));
            }
        }
        int count = 0;
        while(!pq.empty()) {
            Node top = pq.top();
            pq.pop();
            count++;
            if (count == k) return top.v;
            if (top.y < arr[top.x].size() - 1) {
                pq.push(Node(top.x, top.y + 1, arr[top.x][top.y + 1]));
            }
        }
        return -1;
    }
};
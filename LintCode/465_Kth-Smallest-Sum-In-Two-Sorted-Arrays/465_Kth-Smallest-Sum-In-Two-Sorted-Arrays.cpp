struct Node {
    int row;
    int col;
    int val;
    Node (int r, int c, int v) : row(r), col(c), val(v) {}
};

struct cmp {
    bool operator() (const Node & a, const Node & b) {
        return a.val >= b.val;   //minHeap
    }
};

class Solution {
public:
    /**
     * @param A: an integer arrays sorted in ascending order
     * @param B: an integer arrays sorted in ascending order
     * @param k: An integer
     * @return: An integer
     */
    int kthSmallestSum(vector<int> &A, vector<int> &B, int k) {
        int lenA = A.size();
        int lenB = B.size();
        if (lenA == 0 || lenB == 0) return 0;

        vector<vector<int>> visited(lenA, vector<int>(lenB, 0));
        priority_queue<Node, vector<Node>, cmp> minHeap; 
        minHeap.push(Node(0, 0, A[0] + B[0]));
        
        for (int i = 1; i < k; ++i) {
            Node topNode = minHeap.top();
            minHeap.pop();  //totally popped k - 1 elems

            int newR = topNode.row + 1;
            if (newR < lenA && !visited[newR][topNode.col]) {
                minHeap.push(Node(newR, topNode.col, A[newR] + B[topNode.col]));
                visited[newR][topNode.col] = 1;
            }
            
            int newC = topNode.col + 1;
            if (newC < lenB && !visited[topNode.row][newC]) {
                minHeap.push(Node(topNode.row, newC, A[topNode.row] + B[newC]));
                visited[topNode.row][newC] = 1;
            }
        }
        
        return minHeap.top().val;
    }
};
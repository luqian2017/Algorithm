struct Elem {
    int r;
    int c;
    int v;
    Elem(int row = 0, int col = 0, int val = 0) : r(row), c(col), v(val) {}

};

struct cmp {
    bool operator() (const Elem & a, const Elem &b) {
        return (a.v > b.v);
    }
};

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: An integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        
        priority_queue<Elem, vector<Elem>, cmp> pq;  //min-heap
        int nRow = matrix.size();
        int nCol = matrix[0].size();
        
        pq.push(Elem(0, 0, matrix[0][0]));
        vector<vector<int>> visited(nRow, vector<int>(nCol, 0));
        visited[0][0] = 1;
        
        for (int i = 0; i < k - 1; ++i) {
            Elem elem = pq.top();  //totally popped k - 1 elements
            pq.pop();
            
            int newR = elem.r + 1;
            if (newR < nRow && !visited[newR][elem.c]) {
                pq.push(Elem(newR, elem.c, matrix[newR][elem.c]));
                visited[newR][elem.c] = 1;
            }
            
            int newC = elem.c + 1;
            if (newC < nCol && !visited[elem.r][newC]) {
                pq.push(Elem(elem.r, newC, matrix[elem.r][newC]));
                visited[elem.r][newC] = 1;
            }
        }
        
        return pq.top().v;
    }
};
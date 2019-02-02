struct Node {
    int x;
    int y;
    int z;
    Node(int row = 0, int col = 0, int height = 0) : x(row), y(col), z(height) {}
};

struct cmp {
    bool operator() (Node & a, Node & b) {
        return a.z >= b.z;
    }
};

class Solution {
public:
    /**
     * @param heights: a matrix of integers
     * @return: an integer
     */
    int trapRainWater(vector<vector<int>> &heights) {
        
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        
        if (heights.size() == 0) return 0;
        
        int count = 0;  //amount of water
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<int>> visited(m, vector<int>(n, 0));
        priority_queue<Node, vector<Node>, cmp> minHeap;
        
        //push the boundary nodes to the minHeap
        for (int i = 0; i < m; ++i) {
            minHeap.push(Node(i, 0, heights[i][0]));
            minHeap.push(Node(i, n - 1, heights[i][n - 1]));
            visited[i][0] = true;
            visited[i][n - 1] = true;
        }
        
        //push the boundary nodes to the minHeap
        for (int i = 0; i < n; ++i) {
            minHeap.push(Node(0, i, heights[0][i]));
            minHeap.push(Node(m - 1, i, heights[m - 1][i]));
            visited[0][i] = true;
            visited[m - 1][i] = true;
        }
        
        while(!minHeap.empty()) {
            Node topNode = minHeap.top();
            minHeap.pop();
            
            for (int i = 0; i < 4; ++i) {
                int newX = topNode.x + dx[i];
                int newY = topNode.y + dy[i];
                
                if (newX < 0 || newX >= m || newY < 0 || newY >=n || visited[newX][newY]) 
                    continue;
                
                visited[newX][newY] = true;
                
                minHeap.push(Node(newX, newY, max(topNode.z, heights[newX][newY])));
                
                if (topNode.z > heights[newX][newY]) 
                    count += topNode.z - heights[newX][newY];
            }
        }
        
        return count;
    }
};
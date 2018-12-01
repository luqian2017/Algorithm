class Solution {
public:
    struct Point {
        int x;
        int y;
        Point(int row, int col) : x(row), y(col) {}
    };
    
    /**
     * @param targetMap: 
     * @return: nothing
     */
    int shortestPath(vector<vector<int>> &targetMap) {
        vector<int> dirX = {1, 0, -1, 0}; //east, north, west, south
        vector<int> dirY = {0, -1, 0, 1}; //east, north, west, south
     //   vector<vector<int>> visited(targetMap.size(), vector<int>(targetMap[0].size(), 0));

        queue<Point> q;
        q.push(Point(0, 0));
        int pathLen = 0;
        
        while(!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; ++i) {
                Point p = q.front();
                q.pop();
                
                if (targetMap[p.x][p.y] == 2) return pathLen;
                
                targetMap[p.x][p.y] = 1; //set as visited
                
                for (int j = 0; j < 4; ++j) {
                    Point neighborNode = Point(p.x + dirX[j], p.y + dirY[j]);
                    if (validPlace(targetMap, neighborNode)) 
                        q.push(neighborNode);
                }
            }

            pathLen++;
        }
        
        return -1;
    }

private:
    bool validPlace(vector<vector<int>> &grid, Point &p) {
        return (p.x >= 0 && p.x < grid.size() && p.y >= 0 && p.y < grid[0].size()) &&
               (grid[p.x][p.y] >= 0) &&
               (grid[p.x][p.y] != 1);
    }
};
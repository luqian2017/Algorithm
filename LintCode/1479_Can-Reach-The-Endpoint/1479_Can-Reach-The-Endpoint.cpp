struct Coord {
  int x;
  int y;
  Coord() : x(0), y(0) {}
  Coord(int a, int b) : x(a), y(b){}
};

class Solution {
public:
    /**
     * @param map: the map
     * @return: can you reach the endpoint
     */
 
    bool reachEndpoint(vector<vector<int>> &grid) {
        vector<int> dirX = {1, -1, 0, 0};
        vector<int> dirY = {0, 0, 1, -1};
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        queue<Coord> q;
        q.push(Coord(0, 0));
        // int steps = 0; //for this question, it does not need steps as it just returns true/false.
        
        while (!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; ++i) {
                Coord p = q.front();
                q.pop();
                
                if (grid[p.x][p.y] == 9) return true;
                
                for (int j = 0; j < 4; ++j) {
                    Coord neighbor = Coord(p.x + dirX[j], p.y + dirY[j]);
                    
                    //check if 1) p is inside of the grid; 2) not obstacle; 3) unvisited 
                    if (neighbor.x >=0 && neighbor.x < grid.size() && 
                        neighbor.y >=0 && neighbor.y < grid[0].size() &&
                        (grid[neighbor.x][neighbor.y] != 0) &&
                        !visited[neighbor.x][neighbor.y]) {
                        
                        q.push(neighbor);
                        visited[neighbor.x][neighbor.y] = true;
                    }
                }
            }
            //steps++;
        }
        
        return false;
    }
};
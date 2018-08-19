class Solution {
public:
    struct Point {
      int x;
      int y;
      int z;
      Point() : x(0), y(0), z(0) {}
      Point(int a, int b, int c) : x(a), y(b), z(c) {}
    };


    /**
     * @param N: the size of space
     * @param barriers: an array of coordinates represents the position of the barrier
     * @return: the minimum number of steps
     */
    int shortestDistance(int N, vector<vector<int>> &barriers) {
        vector<int> dirX = {0,0,1};
        vector<int> dirY = {0,1,0};
        vector<int> dirZ = {1,0,0};
        
        //initialize grids
        grids.resize(N);  
        for (int i = 0; i < N; ++i) {  
            grids[i].resize(N);  
            for (int j = 0; j < N; ++j) {  
                grids[i][j].resize(N);  
            }
        } 

        queue<Point> q;
        q.push(Point(0,0,0));
        int minSteps = 0;

        while(!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; ++i) {
                Point p = q.front();
                q.pop();
                
                if ((p.x == N-1) && (p.y == N-1) && (p.z == N-1)) {
                    return minSteps;
                }
                
                for (int j = 0; j < 3; ++j) {
                    Point newP = Point(p.x+dirX[j], p.y+dirY[j], p.z+dirZ[j]);
                    if (validMove(newP, N, barriers)) {
                        q.push(newP);
                        grids[newP.x][newP.y][newP.z] = 1;
                        
                    }
                }
            }
            minSteps++;
        }
        
        return -1;
    } 
    
private:
    vector<vector<vector<int>>> grids;
     
    bool validMove(Point p, int N, vector<vector<int>> &barriers) {
        for (auto bar : barriers) {
            if ((p.x == bar[0]) && (p.y == bar[1]) && (p.z == bar[2])) {
                return false;
            }
        }
        
        return p.x >= 0 && p.x < N &&
               p.y >= 0 && p.y < N &&
               p.z >= 0 && p.z < N &&
               !grids[p.x][p.y][p.z];
    } 
    
};
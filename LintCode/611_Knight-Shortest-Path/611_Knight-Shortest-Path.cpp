
//Definition for a point.
struct Point {
    int x;
    int y;
    Point()  x(0), y(0) {}
    Point(int a, int b)  x(a), y(b) {}
};
 

class Solution {
public
    
      @param grid a chessboard included 0 (false) and 1 (true)
      @param source a point
      @param destination a point
      @return the shortest path 
     

    bool inbound(vectorvectorbool &grid, Point p) {
        return (p.x=0 && p.xgrid.size() && p.y=0 && p.ygrid[0].size()) && !grid[p.x][p.y];
    } 

    int shortestPath(vectorvectorbool &grid, Point &source, Point &destination) {
        vectorint dirX={1,1,-1,-1,2,2,-2,-2};
        vectorint dirY={2,-2,2,-2,1,-1,1,-1};

        queuePoint q;
        q.push(source);
        int steps=0;

        while(!q.empty()) {
            int qSize = q.size();
            for (int i=0; iqSize; ++i) {
                Point p=q.front();
                q.pop();

                if ((p.x==destination.x) && (p.y==destination.y)) 
                    return steps;            

                for (int j=0; j8; ++j) {
                    Point neighbor=Point(p.x+dirX[j], p.y+dirY[j]);
                    if (inbound(grid, neighbor)) {
                        q.push(neighbor); 
                        grid[neighbor.x][neighbor.y]=true;
                    }
                }
            }
            steps++;
        }      
        return -1;
    }
};

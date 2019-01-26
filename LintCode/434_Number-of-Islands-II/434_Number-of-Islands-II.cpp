/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
    /**
     * @param n: An integer
     * @param m: An integer
     * @param operators: an array of point
     * @return: an integer array
     */
    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        nRow = n;
        nCol = m;

        //initialize
        father.resize(n * m);
        grid.resize(n * m);
       
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int num = i * m + j;
                father[num] = num;
                grid[num] = 0;
            }
        }
        
        count = 0; //num of islands 
        
        int numOperators = operators.size();
        for (int i = 0; i < numOperators; ++i) {
            add(operators[i].x, operators[i].y);
        }
        
        return result;
    }
    
private:
    
    // left, down, right, up
    // x is index of row, y is index of col
    vector<int> dx = {0, -1, 0, 1};
    vector<int> dy = {-1, 0, 1, 0}; 
    
    //find root
    int find(int x, int y) {
        int num = x * nCol + y;
        int num2 = num;
        
        if (father[num] == num) return num;
        
        int origX = x, origY = y;
        
        while (father[num] != num) {
              num = father[num];
        }
        
        //path compression
        while(father[num2] != num) {
            int temp = father[num2];
            father[num2] = num;
            num2 = temp;
        }
        
        return num;
    }
    
    void add(int x, int y) {
        
        //do not add duplicate node    
        if (grid[x * nCol + y] == 1) {
            result.push_back(count);
            return;  
        }
        
        grid[x * nCol + y] = 1;
        
        int rootA, rootB;
        count++;
    
        for (int i = 0; i < 4; ++i) {
            int newX = x + dx[i];  // new row index
            int newY = y + dy[i];  // new col index
            if ((newX >= 0 ) && (newX < nRow) && (newY >= 0) && (newY < nCol)) {
                int num = newX * nCol+ newY;
                if (grid[num]) {
                    rootA = find(x, y);   //note! each time it needs to recalculate!
                    rootB = find(newX, newY);
                    if (rootA != rootB) {
                        father[rootA] = rootB;
                        count--;
                    }
                }
            }
        }
        result.push_back(count);
    }
    
    vector<int> father;
    vector<int> grid;
    vector<int> result;
    int count;
    int nRow;
    int nCol;
};
struct coordinate {
        int x;
        int y;
        coordinate (int x, int y) {
            this->x=x;
            this->y=y;
        }
    };

    int numIslands(vector<vector<bool>> &grid) {
        int num_row=grid.size();
        if (num_row==0) return 0;

        int num_col=grid[0].size();
        int num_islands=0;

        for (int i=0; i<num_row; ++i) {
            for (int j=0; j<num_col; ++j) {
                if (grid[i][j]) {
                    bfs(grid, i, j);
                    num_islands++;
                }
            }        
        }

        return num_islands;
    }

    void bfs(vector<vector<bool>> &grid, int x, int y) {
        //north, east, west, south
        vector<int> dirX = {0,1,-1,0};
        vector<int> dirY = {1,0,0,-1};    
        queue<coordinate> q;

        q.push(coordinate(x,y)); //also we can use coordinate temp = coordinate(x, y); and q.push(temp);
        grid[x][y]=false;

        while(!q.empty()) {
            coordinate node = q.front();
            q.pop();
            for (int i=0; i<4; i++) {
                coordinate neighbour = coordinate(node.x+dirX[i], node.y+dirY[i]);

                if (!(neighbour.x>=0 && neighbour.x<grid.size() && neighbour.y>=0 && neighbour.y<grid[0].size()))
                    continue;

                if (grid[neighbour.x][neighbour.y]) {
                    grid[neighbour.x][neighbour.y]=false;
                    q.push(neighbour);
                }   
            }
        }
    } 
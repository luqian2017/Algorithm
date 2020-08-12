class Solution {
public:
    /**
     * @param x: an array of integers, the x coordinates of each city[i]
     * @param y: an array of integers, the y coordinates of each city[i]
     * @param c: an array of strings that represent the names of each city[i]
     * @param q: an array of strings that represent the names of query locations
     * @return: the closest city for each query
     */
    vector<string> NearestNeighbor(vector<int> &x, vector<int> &y, vector<string> &c, vector<string> &q) {
        int cx, cy;
        vector <string> near;
        for(int queryIndex = 0; queryIndex < q.size(); queryIndex++)
        {
            string city = "NONE";
            int minDistance = 0;
            int findIndex = 0;             
            for(int i = 0; i < c.size(); i++)
            {
                if(c[i] == q[queryIndex])
                {
                    cx = x[i];
                    cy = y[i];
                    findIndex = i;
                    break;
                }
            }
            
            for(int i = 0; i < c.size(); i++)
            {
                if(i == findIndex)
                {
                    continue;
                }
                
                if(x[i] == cx)
                {
                    if(abs(cy - y[i]) < minDistance || minDistance == 0)
                    {
                        minDistance = abs(cy - y[i]);
                        city = c[i];
                    }
                    if(abs(cy - y[i]) == minDistance && c[i] < city)
                    {
                        minDistance = abs(cy - y[i]);
                        city = c[i];
                    }
                }
                
                if(y[i] == cy)
                {
                    if(abs(cx - x[i]) < minDistance || minDistance == 0)
                    {
                        minDistance = abs(cx - x[i]);
                        city = c[i];
                    }
                    
                    if(abs(cx - x[i]) == minDistance && c[i] < city)
                    {
                        minDistance = abs(cx - x[i]);
                        city = c[i];
                    }
                }
             }
            
            near.push_back(city);
        
        }
        return near;
    }
};
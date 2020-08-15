class Solution {
public:
    /**
     * @param n: an integer,denote the number of cities
     * @param roads: a list of three-tuples,denote the road between cities
     * @return: return the minimum cost to travel all cities
     */
    int minCost(int n, vector<vector<int>> &roads) {
        vector<vector<int>> cityLink(n, vector<int>(n, INT_MAX));
        for (auto & road: roads){
            int cityA = road[0] - 1, cityB = road[1] - 1, dist = road[2];
            cityLink[cityA][cityB] = cityLink[cityB][cityA] = min(cityLink[cityA][cityB], dist);
        }
        
        vector<bool> visited(n, false);
        vector<int> subset;
        
        subset.push_back(0); //city 0 
        visited[0] = true;
        
        dfs(cityLink, subset, visited, 0);
    	return minTravelCost;
    }

private:
    int minTravelCost = INT_MAX;
    void dfs(vector<vector<int>> & cityLink, vector<int> & subset, vector<bool> & visited, int cost) {
        int n = cityLink.size();
        if (subset.size() == n) {
            minTravelCost = min(minTravelCost, cost);
            return;
        }
        
        if (cost > minTravelCost) return;
        
        for (int i = 0; i < n; ++i) {
            int lastCity = subset.back();
            
            if (visited[i] || cityLink[lastCity][i] == INT_MAX) continue;
            
            subset.push_back(i);
            visited[i] = true;
            dfs(cityLink, subset, visited, cost + cityLink[lastCity][i]);
            visited[i] = false;
            subset.pop_back();
        }
    }
    
};

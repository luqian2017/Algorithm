class Solution {
public:
    /**
     * @param n: an integer,denote the number of cities
     * @param roads: a list of three-tuples,denote the road between cities
     * @return: return the minimum cost to travel all cities
     */
    int minCost(int n, vector<vector<int>> &roads) {
        vector<vector<int>> cityLink(n, vector<int>(n, INT_MAX));
        vector<vector<int>> dp(n, vector<int>(1 << n, INT_MAX));
        
        for (auto & road: roads){
            int cityA = road[0] - 1, cityB = road[1] - 1, dist = road[2];
            cityLink[cityA][cityB] = cityLink[cityB][cityA] = min(cityLink[cityA][cityB], dist);
        }

        priority_queue<pair<int, pair<int,int>>> maxHeap; //<cost, <city index, state>>, sort by cost
        maxHeap.push({0, {0, 1}}); //init: the first city is visited
      
        dp[0][1] = 0; //cost of city 0 to itself is 0
        while (!maxHeap.empty()){
            auto now = maxHeap.top();
            maxHeap.pop();
    		int cost = now.first, city = now.second.first, state = now.second.second;
    		
    		for(int i = 0; i < n; ++i){
    		    if (cityLink[city][i] == INT_MAX) continue;
    		    if ((state & (1 << i)) == 0) { //if city i has not been visited
        			int new_state = (state | (1 << i)); //old state + city i
        			if(dp[i][new_state] > dp[city][state] + cityLink[city][i]) {
        				dp[i][new_state] = dp[city][state] + cityLink[city][i];
        				maxHeap.push({dp[i][new_state], {i, new_state}});
    			    }
    		    }
    		}
        }
        
        int minCost = dp[0][0];
    	for(int i = 0; i < n; i++) {
    		minCost = min(minCost, dp[i][(1 << n) - 1]);
    	}
    	
    	return minCost;
    }
};

/**
 * Definition for a Connection.
 * class Connection {
 * public:
 *   string city1, city2;
 *   int cost;
 *   Connection(string& city1, string& city2, int cost) {
 *       this->city1 = city1;
 *       this->city2 = city2;
 *       this->cost = cost;
 * }
 */
 
//struct cmp {
//    bool  operator()(Connection &a, Connection &b) {
//       return a.cost < b.cost;
//    }    
//}cmpObject;

bool cmp(const Connection& c1, const Connection& c2) {
    if (c1.cost != c2.cost)
        return c1.cost < c2.cost;

    if (c1.city1 != c2.city1)
        return c1.city1 < c2.city1;

    return c1.city2 < c2.city2;
}

class Solution {
public:
    /**
     * @param connections given a list of connections include two cities and cost
     * @return a list of connections from results
     */
    vector<Connection> lowestCost(vector<Connection>& connections) {
        // MST - Prime algorithm
        vector<Connection> result;
        if (connections.size() == 0) return result;

	    set<string> nameSet;
        for (auto c : connections) {
            nameSet.insert(c.city1);
            nameSet.insert(c.city2);
        }
        int len = nameSet.size();
        vector<string> nameVec;
        
        map<string, int> nameMap; //city_name, city_index
        int index = 0;
        for (auto s : nameSet) {
            nameMap[s] = index++;
            nameVec.push_back(s);
        }
        
        string dummy = "INVALID";
        vector<vector<Connection>> graph(len, vector<Connection>(len, Connection(dummy, dummy, INT_MAX))); //need to do this because Connection does not provide default construction

        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                graph[i][j] = Connection(nameVec[i], nameVec[j], INT_MAX);
            }
        }

        for (auto c : connections) {
            graph[nameMap[c.city1]][nameMap[c.city2]] = c;
        }

        vector<bool> visited(len, false);
        visited[0] = true;
        
        map<int, Connection *> dist; //city_index, distance to mst

        for (int i = 0; i < len; ++i) {
            if (graph[0][i].cost < graph[i][0].cost)
                dist[i] = &graph[0][i];
            else
                dist[i] = &graph[i][0];
        }

        for (int i = 1; i < len; ++i) {
            int minDist = INT_MAX;
            for (int j = 0; j < len; ++j) {
                if (!visited[j] && dist[j]->cost < minDist) {
                    minDist = dist[j]->cost;
                    index = j;
                }
            }
            
            if (minDist == INT_MAX) return vector<Connection>();
            visited[index] = true;
            result.push_back(*dist[index]);

            for (int j = 0; j < len; ++j) {
                if (!visited[j]) {
                  if (dist[j]->cost > graph[index][j].cost) dist[j] = &graph[index][j];
                  if (dist[j]->cost > graph[j][index].cost) dist[j] = &graph[j][index];
                }
            }
        }
       
 //       sort(result.begin(), result.end(), cmpObject);
        sort(result.begin(), result.end(), cmp);
        return result;
    }

};

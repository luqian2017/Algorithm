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

bool operator < (const Connection & a, const Connection & b) {
    if (a.cost == b.cost) {
        if (a.city1 == b.city1) {
            return a.city2 < b.city2;
        } else {
            return a.city1 < b.city1;
        }
    } else {
        return a.cost < b.cost;
    }
}

class Solution {
public:
    /**
     * @param connections given a list of connections include two cities and cost
     * @return a list of connections from results
     */
    vector<Connection> lowestCost(vector<Connection>& connections) {
        sort(connections.begin(), connections.end());
        unordered_map<string, int> hashmap; //cityname, index
        int index = 0;
        
        for (auto connection : connections) {
            if (hashmap.find(connection.city1) == hashmap.end()) {
                hashmap[connection.city1] = index++;
            }
            if (hashmap.find(connection.city2) == hashmap.end()) {
                hashmap[connection.city2] = index++;
            }
        }
        
        int numCities = index; 
        father.resize(numCities);
        for (int i = 0; i < numCities; ++i) {
            father[i] = i;
        }
        vector<Connection> results;
        
        for (auto connection : connections) {
    
            int cityIndex1 = hashmap[connection.city1];
            int cityIndex2 = hashmap[connection.city2];

            int root1 = find(cityIndex1);
            int root2 = find(cityIndex2);
            if (root1 != root2) {
                father[root1] = root2;
                results.push_back(connection);
            }
        }
        
        if (results.size() != numCities - 1) return {};
        return results;
    }
    
private:
    vector<int> father;
    int find(int num) {
        if (father[num] == num) return num;
        father[num] = find(father[num]);
        return father[num];
    }
};
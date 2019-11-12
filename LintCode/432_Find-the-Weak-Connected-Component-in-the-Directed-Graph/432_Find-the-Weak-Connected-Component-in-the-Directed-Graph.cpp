/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */


class Solution {
public:
    /*
     * @param nodes: a array of Directed graph node
     * @return: a connected set of a directed graph
     */
    vector<vector<int>> connectedSet2(vector<DirectedGraphNode*> nodes) {
        int n = nodes.size();
       
        //initialize, each node's father is itself
        for (auto node : nodes) {
            father[node->label] = node->label;
        }
        
        //union
        for (int i = 0; i < n; ++i) {
            for (auto neighbor : nodes[i]->neighbors) {
                merge(nodes[i]->label, neighbor->label);
            }
        }
        
        map<int, vector<int>> component; //father, children
        for (int i = 0; i < n; ++i) {
            int findFather = find(father[nodes[i]->label]);
            if (component.find(findFather) == component.end()) {
                component[findFather] = vector<int>();
            }
            
            component[findFather].push_back(nodes[i]->label); 
        }
        
        for (auto m : component) {
            result.push_back(m.second);
        }
        return result;
    }
    
private:
    map<int, int> father;   
    //vector<int> father; //wrong, because label can be negative
    vector<vector<int>> result;

    int find(int x) {
        if (x == father[x]) {
            return x;
        }
        father[x] = find(father[x]);
        return father[x];
    }
    
    void merge(int x, int y) {
        int fatherX = find(x);  //not fatherX = father[x];
        int fatherY = find(y);
        if (fatherX != fatherY) {
            father[fatherX] = fatherY;   //not father[y]
        }
    }
    
};
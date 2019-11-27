class Node{

public:
    int id, tp, location;
    Node(){}
    Node(int id, int tp, int location):id(id), tp(tp), location(location){}

    bool operator < (const Node & A)const {
        return location < A.location;
    }
};


class Solution {
public:
    /**
     * @param stores: The location of each store.
     * @param houses: The location of each house.
     * @return: The location of the nearest store to each house.
     */
    vector<int> findNearestStore(vector<int> &stores, vector<int> &houses) {
        // 
        vector<Node> nodes;
        vector<int> answer(houses.size(), -1);
        for(int i = 0; i < stores.size(); i++){
            nodes.push_back(Node(i, 1, stores[i]));
        }
        
        for(int i = 0; i < houses.size(); i++) {
            nodes.push_back(Node(i, 0, houses[i]));
        }

        sort(nodes.begin(), nodes.end());
        int p = -1;
        for(int i = 0; i < nodes.size(); i++) {
            if(nodes[i].tp == 1) {
                p = nodes[i].location;
            } else {
                answer[nodes[i].id] = p;
            }
        }
        p = -1;
        for(int i = nodes.size() - 1; i >= 0; i--) {
            if(nodes[i].tp == 1) {
                p = nodes[i].location;
            } else if( p == -1 ){
                continue;
            } else {
                int cur = nodes[i].id;
                int curLocation = nodes[i].location;
                if(answer[cur] == -1 || 
                   curLocation - answer[cur] > p - curLocation ) {
                    answer[cur] = p;
                }
            } 
        }

        return answer;
        
    }
};
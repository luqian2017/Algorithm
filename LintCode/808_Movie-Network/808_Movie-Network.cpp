struct Node {
    int index;
    int rating;
    Node (int id = 0, int rt = 0) : index(id), rating(rt) {}
    bool operator < (const Node & a) const {    //minHeap
        return rating > a.rating;
    }
};

class Solution {
public:
    /**
     * @param rating: the rating of the movies
     * @param G: the realtionship of movies
     * @param S: the begin movie
     * @param K: top K rating 
     * @return: the top k largest rating moive which contact with S
     */
    vector<int> topKMovie(vector<int> &rating, vector<vector<int>> &G, int S, int K) {
        int n = rating.size();
        vector<bool> visited(n, false);
        
        int m = G.size(); 
        if (m == 0) return {};
        
        priority_queue<Node> minHeap;
        queue<Node> q;
        
        visited[S] = true;
        
        for (int i = 0; i < G[S].size(); ++i) {
            visited[G[S][i]] = true;
            q.push(Node(G[S][i], rating[G[S][i]]));
        }
        
        while(!q.empty()) {
            Node top = q.front();
            q.pop();
            if (minHeap.size() < K) {
                minHeap.push(top);
            } else if (top.rating > minHeap.top().rating) {
                minHeap.pop();
                minHeap.push(top);
            }
            for (int i = 0; i < G[top.index].size(); ++i) {
                if (!visited[G[top.index][i]]) {
                    q.push(Node(G[top.index][i], rating[G[top.index][i]]));
                    visited[G[top.index][i]] = true;
                }
            }
        }
        vector<int> result;
        while(!minHeap.empty()) {
            result.push_back(minHeap.top().index);
            minHeap.pop();
        }
        return result;
    }
};
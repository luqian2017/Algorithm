class Solution {
public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */
    string alienOrder(vector<string> &words) {
        map<char, set<char>> graph = buildGraph(words);
        return topologicalSorting(graph);
    }
    
private:
    map<char, set<char>> buildGraph(vector<string> &words) {
        map<char, set<char>> graph;
        
        //put all the chars in graph, the set is empty at this time
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words[i].size(); ++j) {
                if (graph.find(words[i][j]) == graph.end())
                    graph[words[i][j]] = {};
            }
        }

        for (int i = 0; i < words.size() - 1; ++i) {
            int len = min(words[i].size(), words[i + 1].size());
            for (int j = 0; j < len; ++j) {
                if (words[i][j] != words[i + 1][j]) {
                    graph[words[i][j]].insert(words[i + 1][j]);
                    break;
                }
            }
        }
        return graph;
    }
    
    map<char, int> getIndegree(map<char, set<char>> graph) {
        map<char, int> indegree;
        for (auto elem : graph) {
            indegree[elem.first] = 0;
        }
        for (auto elem: graph) {
            for (auto c : elem.second) {
                indegree[c]++;
            }
        }
        return indegree;
    }
    
    string topologicalSorting(map<char, set<char>> graph) {
        map<char, int> indegree = getIndegree(graph);
        priority_queue<char, vector<char>, greater<char>> pq;   //minHeap
        string str;
        for (auto elem : indegree) {
            if (indegree[elem.first] == 0) {
                pq.push(elem.first);
            }
        }
        
        
        while(!pq.empty()) {
            char topChar = pq.top();
            pq.pop();
            str += topChar;
            for (char neighbor : graph[topChar]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    pq.push(neighbor);
                }
            }
        }

        if (str.size() != indegree.size()) return "";
        return str;
    }
};
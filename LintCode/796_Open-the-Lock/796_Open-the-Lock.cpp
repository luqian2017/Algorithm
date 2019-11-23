class Solution {
public:
    /**
     * @param deadends: the list of deadends
     * @param target: the value of the wheels that will unlock the lock
     * @return: the minimum total number of turns 
     */
    int openLock(vector<string> &deadends, string &target) {
        int n = deadends.size();
        
        string start = "0000";
        if (start == target) return 0;

        unordered_set<string> deadset;
        for (int i = 0; i < n; ++i) {
            if (start == deadends[i]) return -1;
            deadset.insert(deadends[i]);
        }
        
        queue<string> q;
        q.push(start);
        unordered_set<string> visited;
        visited.insert(start);
        int round = 0;
        
        while(!q.empty()) {
            int qSize = q.size();
            round++;
            for (int i = 0; i < qSize; ++i) {
                string frontNode = q.front();
                if (frontNode == target) return round - 1;
                q.pop();
                
                for (int j = 0; j < 4; ++j) {
                    string newNode = frontNode.substr(0, j) + to_string(((frontNode[j] - '0') + 1) % 10) + frontNode.substr(j + 1);
                    
                 //   if (newNode == target) return round;
                    
                    if (visited.find(newNode) == visited.end() &&
                        deadset.find(newNode) == deadset.end()) {
                        q.push(newNode);
                        visited.insert(newNode);
                    }
                    
                    newNode = frontNode.substr(0, j) + to_string(((frontNode[j] - '0') + 9) % 10) + frontNode.substr(j + 1);
                    
                  //  if (newNode == target) return round;
                    
                    if (visited.find(newNode) == visited.end() &&
                        deadset.find(newNode) == deadset.end()) {
                        q.push(newNode);
                        visited.insert(newNode);
                    }
                }
            }
            
        }
        
        return -1;
    }
};
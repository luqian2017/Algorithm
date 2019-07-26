class Solution {
public:
    /**
     * @param pid: the process id
     * @param ppid: the parent process id
     * @param kill: a PID you want to kill
     * @return: a list of PIDs of processes that will be killed in the end
     */
    vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill) {
        int n = pid.size();
        if (n == 0) return vector<int>();

        
        for (int i = 0; i < n; ++i) {
            father[pid[i]] = ppid[i];
        }
        
        killed.insert(kill);
        for (int i = 0; i < n; ++i) {
            if (killed.find(pid[i]) != killed.end()) continue;
            
            if (findParent(pid[i], ppid, kill)) {
                int node = pid[i];
                while(node != kill && node != 0) {
                    killed.insert(node);
                    node = father[node];
                }
            }
        }
        vector<int> result(killed.begin(), killed.end());
        return result;
    }

private:
    bool findParent(int node, vector<int> &ppid, int target) {
        if (node == target) return true;
        while(node != target && node != 0) {
            node = father[node];
            if (node == 0) return false;
            if (killed.find(node) != killed.end()) return true;
            if (node == target) return true;
        }
        
        return false;
    } 
    
    set<int> killed;
    map<int, int> father;
};
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
        unordered_map<int, int> father;
        vector<int> result;
        
        result.resize(0);
        for (int i = 0; i < n; ++i) {
            father[pid[i]] = ppid[i];
        }
        
        for (int i = 0; i < n; ++i) {
            int node = pid[i];

            while(node != 0) {
                if (node == kill) {
                    result.push_back(pid[i]);
                    break;
                }
                node = father[node];
            }    
        }
        
        return result;
    }
};
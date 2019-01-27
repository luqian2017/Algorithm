class Solution {
public:
    /**
     * @param accounts: List[List[str]]
     * @return: return a List[List[str]]
     */
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        vector<vector<string>> result;
        
        for (auto account : accounts) {
            int len = account.size();
            for (int i = 1; i < len; ++i) {
                father[account[i]] = account[i];
                owner[account[i]] = account[0];
            }
        }
        
        // union all the emails under the same account
        for (auto account : accounts) {
            int len = account.size();
            for (int i = 2; i < len; ++i) {
                connect(account[i], account[1]); // let email1 be the root of all other emails under the same account
            }
        }
        
        for (auto account : accounts) {
            int len = account.size();
            for (int i = 1; i < len; ++i) {
                mp[find(account[i])].insert(account[i]);  //account[1] <-> set of account[i]s
            }
        }
        
        for (auto m : mp) {
            vector<string> record;
            record.push_back(owner[m.first]);
            record.insert(record.end(), m.second.begin(), m.second.end());  //there is no append() for C++ vector
            result.push_back(record);
        }
        
        return result;
    }
    
    
private:
    unordered_map<string, string> father;   //note it is a map instead of a vector
    unordered_map<string, string> owner;
    unordered_map<string, set<string>> mp;
    
    string find(string & s) {
        if (father[s] == s) return s;
        //path compression
        return father[s] = find(father[s]);
    }
    
    void connect(string & a, string & b) {
        string fatherA = find(a);
        string fatherB = find(b);
        if (fatherA != fatherB) father[fatherA] = fatherB;
    }
};
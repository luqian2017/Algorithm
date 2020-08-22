class Solution {
public:
    /**
     * @param employees: information of the employees
     * @param friendships: the friendships of employees
     * @return: return the statistics
     */
     
    vector<string> stringSplitter(string text){
        std::vector<std::string> tokens;
        std::size_t start = 0, end = 0;
        string sep = ", ";
        while ((end = text.find(sep, start)) != std::string::npos) {
            if (end != start) {
              tokens.push_back(text.substr(start, end - start));
            }
            start = end + 2;
        }
        if (end != start) {
           tokens.push_back(text.substr(start));
        }
        return tokens;
    }

    vector<string> departmentStatistics(vector<string>& employees, vector<string>& friendships) {
        vector<string> ans;
        unordered_map <string, bool> vis; // mark vis[id] = true when id.dept!= friend dept
        unordered_map <string, int> deptCnt; // <department, # of friendships in another department>
        unordered_map <string, int> countInDept; // <department, # of employees>
        unordered_map <string, string> id2Dept; // <id, department>
        
        for(int i = 0; i < employees.size(); i++){
            vector<string> currEmp = stringSplitter(employees[i]);
            id2Dept[currEmp[0]] = currEmp[2];
            countInDept[currEmp[2]]++;
        }
        
        for(int i = 0; i < friendships.size(); i++){
            vector<string> friendList = stringSplitter(friendships[i]);
            string employeeID0 = friendList[0], employeeID1 = friendList[1];
            string department0 = id2Dept[employeeID0], department1 = id2Dept[employeeID1]; 
            if(department0 != department1) {
                if(vis[employeeID0] == false){
                    deptCnt[department0]++;
                    vis[employeeID0] = true;
                }
                if(vis[employeeID1] == false){
                    deptCnt[department1]++;
                    vis[employeeID1] = true;
                }
            }
        }
        
        for(auto it = countInDept.begin(); it != countInDept.end(); it++){
            string record = it->first + ": "+ to_string(deptCnt[it->first]) + " of " + to_string(countInDept[it->first]);
            ans.push_back(record);
        }
        
        return ans;
        
    }
};
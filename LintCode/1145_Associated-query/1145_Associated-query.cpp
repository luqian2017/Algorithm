class Solution {
public:
    /**
     * @param datalist1: a list represents the employee table
     * @param datalist2: a list represents the employee hours table
     * @return: Returns a list of strings represents the datalist3
     */
    vector<vector<string>> getList(vector<vector<string>> &datalist1, vector<vector<string>> &datalist2) {
        int num_employee = datalist1.size();
        if (num_employee == 0) return {{}};
        
        vector<vector<string>> result(num_employee, vector<string>(5));
        for (int i = 0; i < num_employee; ++i) {
            result[i][0] = datalist1[i][1]; 
            
            int month_id = 0, sum_hours = 0;

            month_id = stoi(datalist2[i][1]);
            result[i][month_id] = datalist2[i][2];
            sum_hours += stoi(datalist2[i][2]);
            
            month_id = stoi(datalist2[i][3]);
            result[i][month_id] = datalist2[i][4];
            sum_hours += stoi(datalist2[i][4]);

            month_id = stoi(datalist2[i][5]);
            result[i][month_id] = datalist2[i][6];
            sum_hours += stoi(datalist2[i][6]);

            result[i][4] = to_string(sum_hours);
        }
        
        return result;        
    }
};
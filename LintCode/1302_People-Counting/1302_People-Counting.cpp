class Solution {
public:
    /**
     * @param wage: Salaries of all employees
     * @param ask: Number of inquiries
     * @return: Every time an answer is asked
     */
    vector<int> PeopleCounting(vector<int> &wage, vector<int> &ask) {
        int wage_len = wage.size();
        int ask_len = ask.size();
        
        unordered_map<int, int> um; // <wage, freq>
        
        for (int i = 0; i < wage_len; ++i) {
            um[wage[i]]++;
        }
        
        vector<int> res;
        for (int j = 0; j < ask_len; ++j) {
            res.push_back(um[ask[j]]);
        }
        
        return res;
    }
};
class Solution {
public:
    /**
     * @param digits: A digital string
     * @return: all posible letter combinations
     */
    vector<string> letterCombinations(string &digits) {
        if (digits.size() == 0) return {};
        string sol = "";
        vector<string> sols;
        
        helper(digits, 0, sol, sols);
       
        return sols;
    }
private:
    map<char, vector<char>> dict = {{'2', {'A', 'B', 'C'}}, {'3', {'D', 'E', 'F'}}, 
                                   {'4', {'G', 'H', 'I'}}, {'5', {'J', 'K', 'L'}}, 
                                   {'6', {'M', 'N', 'O'}}, {'7', {'P', 'Q', 'R', 'S'}}, 
                                   {'8', {'T', 'U', 'V'}}, {'9', {'W', 'X', 'Y', 'Z'}}};
    
    void helper(string &digits, int pos, string &sol, vector<string> &sols) {
        
     //   cout << "pos = " << pos << " sol = " << sol << endl;
        if (sol.size() == digits.size()) {
            sols.push_back(sol);
        }
        
     //   for (int i = pos; i < digits.size(); ++i) {
            for (int j = 0; j < dict[digits[pos]].size(); ++j) {
                
                sol = sol + (char)(dict[digits[pos]][j] + ('a' - 'A'));
                helper(digits, pos + 1, sol, sols);
                sol = sol.substr(0, sol.size() - 1); 
            //    helper(digits, pos + 1, sol, sols);
            }
     //   }
    }     
};
class Solution {
public:
    /**
     * @param num: a string contains only digits 0-9
     * @param target: An integer
     * @return: return all possibilities
     */
    vector<string> addOperators(string &num, int target) {
        if (num.size() == 0) return {};
        vector<string> result;
        string opts = "";
        set<string> sols;
        int curVal = num[0] - '0';
        helper(num, target, 1, opts, curVal, sols);
        result.assign(sols.begin(), sols.end());
        return result;
    }
    
private:
    void helper(string &num, int target, int index, string opts, int currVal, set<string> &sols) {
        if (index == num.size()) {
            if (currVal == target) {
                string sol = string() + num[0];
                for (int i = 0; i < opts.size(); ++i) {
                    sol = sol + opts[i] + num[i + 1];
                }
                sols.insert(sol);
            }
            return;
        }
        
        if (index > 1) {
            if (opts[index - 2] == '+') {
                helper(num, target, index + 1, opts + "*", currVal - (num[index - 1] - '0') + (num[index - 1] - '0') * (num[index] - '0'), sols);
            } else if (opts[index - 2] == '-') {
                helper(num, target, index + 1, opts + "*", currVal + (num[index - 1] - '0') - (num[index - 1] - '0') * (num[index] - '0'), sols);
            }
        }
       
        if (index == 1 || opts[index - 2] == '*') {
            helper(num, target, index + 1, opts + '*', currVal * (num[index] - '0'), sols);
        }
        
        helper(num, target, index + 1, opts + '+', currVal + (num[index] - '0'), sols);
        
        helper(num, target, index + 1, opts + '-', currVal - (num[index] - '0'), sols);
        
        return;        
    }
};
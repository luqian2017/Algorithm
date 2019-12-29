

class Solution {
public:
    /**
     * @param num: a string contains only digits 0-9
     * @param target: An integer
     * @return: return all possibilities
     */
    vector<string> addOperators(string &num, int target) {
        int n = num.size();
        if (n == 0) return vector<string>();
        string sol;
        dfs(num, 0, sol, 0, 0, target);
        return sols;
    }

private:
    vector<string> sols;
    void dfs(string &num, int index, string sol, long long sum, long long prevFactor, int target) {
        int n = num.size();
        
        if (index == n && target == sum) {
            sols.push_back(sol);
            return;
        }
        
        for (int i = index; i < n; ++i) {
            string numStr = num.substr(index, i - index + 1);
            long long number = stoll(numStr);
            if (index == 0) {
                dfs(num, i + 1, numStr, number, number, target);
            } else {
                dfs(num, i + 1, sol + '+' + numStr, sum + number, number, target);
                dfs(num, i + 1, sol + '-' + numStr, sum - number, -number, target);
                dfs(num, i + 1, sol + '*' + numStr, sum - prevFactor + prevFactor * number, prevFactor * number, target);
            }
            
            if (num[index] == '0') break;  //to avoid "00"
        }
     
    }
};
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        dfs(s, 0, "", res);
        return res;
    }

private:
    bool isValid(string s) {
       if (s.empty() || s.size() > 3 || (s.size() > 1 && s[0] == '0')) return false;
       int res = atoi(s.c_str());
       return (res >= 0 && res <= 255);
    }
    
    void dfs(string s, int level, string output, vector<string> &res) {
        if (level == 4) {
            if (s.empty()) res.push_back(output);
            return;
        }
        for (int i = 1; i <= 3; ++i) {
            if (s.size() >= i && isValid(s.substr(0, i))) {
                string new_output = output + s.substr(0, i);
                if (level < 3) new_output = new_output + ".";
                dfs(s.substr(i), level + 1, new_output, res);
            } 
        }
    }
};
class Solution {
public:
    /**
     * @param s: The input string
     * @return: Return all possible results
     */
    vector<string> removeInvalidParentheses(string &s) {
        string sol;
        vector<string> results;

        if (s.empty()) {
            results.push_back("");
            return results;
        }

        int l_more = 0;   // shows # of extra '('
        int r_more = 0;   // shows # of extra ')'

        for (int i = 0; i < s.size(); ++i) {

            if (s[i] == '(') {
                l_more++;
            }  

            if (s[i] == ')') {
                if (l_more > 0)
                    l_more--;
                else
                    r_more++;
            }
        }

        helper(s, 0, l_more, r_more, results);

        return results;
    }

private:
    bool isVald(string &s) {
        int count = 0;
        for (auto c : s) {
            if (c == '(') count++;
            if (c == ')') {
                count--;
                if (count < 0) return false;
            }
        }

        return (count == 0);
    }

    void helper(string &s, int index, int l_more, int r_more, vector<string> & results) {

        if (l_more == 0 && r_more == 0) {
            if (isVald(s)) {
                results.push_back(s);
                return;
            }
        }

        for (int i = index; i < s.size(); ++i) {
            if (i != index && s[i] == s[i-1])    //去重, if ))) or (((, just remove the last one)
                continue;

            if (s[i] == '(' && l_more > 0) {
                string new_str = s.substr(0, i) + s.substr(i + 1);    
                  //if index==0, substr(0,index) = ""
                helper(new_str, i, l_more - 1, r_more, results);  //note here is still i !!!
            }

            if (s[i] == ')' && r_more > 0) {
                string new_str = s.substr(0, i) + s.substr(i + 1);
                helper(new_str, i, l_more, r_more - 1, results);
            }
        }
    }

};
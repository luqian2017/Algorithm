
class Solution {
public:
    /*
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: a list of lists of string
     */
    map<string, vector<string>> Str2NextStrs;
    vector<vector<string>> results;

    vector<vector<string>> findLadders(string &start, string &end, unordered_set<string> &dict) {
        map<string, int> StrSteps;
        vector<string> sol;
        dict.insert(end); //否则如果dict里面没有end，输出[]
        bfs(start, end, dict, StrSteps);
        sol.push_back(start);
        dfs(start, end, StrSteps, sol);
        return results;
    }


    void bfs(string& start, string& end, 
             unordered_set<string> &dict, 
             map<string, int> &StrSteps) {
        queue<string> q;
        q.push(start);
        StrSteps[start] = 0;
        while (!q.empty()) {

            string s = q.front(); q.pop();
            if (s == end) break;

            vector<string> nextStrs;

            for (int i = 0; i < s.size(); ++i) {
                string newStr = s;
                for (char c = 'a'; c <= 'z'; c++) {
                    newStr[i] = c;
                    if (c == s[i] || dict.find(newStr) == dict.end()) 
                        continue;

                    if (StrSteps.find(newStr) == StrSteps.end()) {
                        q.push(newStr);
                        StrSteps[newStr] = StrSteps[s] + 1;
                    }
                    nextStrs.push_back(newStr);
                }
            }
            Str2NextStrs[s] = nextStrs;
        }
    }


    void dfs(string& start, string& end, 
             map<string, int> &StrSteps, 
             vector<string> &sol){

        if (start == end) 
            results.push_back(sol);

        vector<string> nextStrs = Str2NextStrs[start];
        for (int i = 0; i < nextStrs.size(); i++) {

            if (StrSteps[nextStrs[i]] != StrSteps[start] + 1) continue;

            sol.push_back(nextStrs[i]);
            dfs(nextStrs[i], end, StrSteps, sol);
            sol.pop_back();
        }
    }
};
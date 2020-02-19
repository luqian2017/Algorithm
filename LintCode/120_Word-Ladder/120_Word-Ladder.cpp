class Solution {
public:
    /*
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: An integer
     */
    int ladderLength(string &start, string &end, unordered_set<string> &dict) {
        int n = start.size();
        if (n != end.size()) return 0;
        
        queue<string> q;
        q.push(start);
        int step = 1;
        while(!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; ++i) {
                string curStr = q.front();
                q.pop();
                for (int j = 0; j < n; ++j) {
                    char curChar = curStr[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == curChar) continue;
                        curStr[j] = c;
                        if (curStr == end) return step + 1;
                        if (dict.find(curStr) != dict.end()) {
                            q.push(curStr);
                            dict.erase(curStr); //important!!
                        }
                    }
                    curStr[j] = curChar;  //important!
                }
            }
            step++;
        }
        
        return 0;
    }
};
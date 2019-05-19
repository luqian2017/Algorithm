class Solution {
public:
    /*
     * @param s: a string
     * @param dict: a set of n substrings
     * @return: the minimum length
     */
    int minLength(string &s, unordered_set<string> &dict) {
        int N = s.size();
        if (N == 0) return 0;
        
        queue<string> q;
        unordered_set<string> hashSet;
        
        int minLen = N;
        q.push(s);
        hashSet.insert(s);

        while(!q.empty()) {
            string s = q.front();
            q.pop();
            
            for (auto str : dict) {
                int pos = s.find(str);
                
                while(pos != -1) {
                //if (pos != -1) {
                    string new_s = s.substr(0, pos) + s.substr(pos + str.size());
                    if (hashSet.find(new_s) == hashSet.end()) {
                        q.push(new_s);
                        hashSet.insert(new_s);
                        minLen = min(minLen, (int)new_s.size());
                    }
                    pos = s.find(str, pos + 1);   //important!
                }
            }
        }
        
        return minLen;
    }
};
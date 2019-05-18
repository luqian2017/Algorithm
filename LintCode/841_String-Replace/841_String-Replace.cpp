struct compare {
    bool operator() (string & a, string & b) {
        return a.size() > b.size();
    }
} cmp;

class Solution {
public:
    /**
     * @param a: The A array
     * @param b: The B array
     * @param s: The S string
     * @return: The answer
     */
    string stringReplace(vector<string> &a, vector<string> &b, string &s) {
        int M = a.size();
        int N = b.size();
        int K = s.size();
        if (M != N || M == 0 || K == 0) return "";
        
        unordered_map<string, string> um;
        
        for (int i = 0; i < M; ++i) {
            um[a[i]] = b[i];
        }
        
        sort(a.begin(), a.end(), cmp);
        
        int index = 0; //index in a[]
        int pos = 0;
    
        while(pos < K) {
            for (int i = 0; i < M; ++i) {
                int len = a[i].size();
                if (pos + len > K) continue;
                string subString = s.substr(pos, len);
                //if (s.find(a[i]) == pos) {   //consume too much time!!!
                if (subString == a[i]) {
                    s.replace(pos, len, um[s.substr(pos, len)]);
                    pos += len - 1; //remember to -1 as it will pos++ below
                    break;
                }
            }
            pos++;
        }
        
        return s;
    }
};
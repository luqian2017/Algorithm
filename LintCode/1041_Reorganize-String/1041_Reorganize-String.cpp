class Solution {
public:
    /**
     * @param S: a string
     * @return: return a string
     */
    string reorganizeString(string &S) {
        int n = S.size();
        string result;
        if (n == 0) return result;
        
       // int thresh = (n & 0x1) ? n / 2 + 1 : n / 2;
        
        unordered_map<char, int> um;
        priority_queue<pair<int, char>> pq;
        
        for (int i = 0; i < n; ++i) {
            um[S[i]]++;
            if (um[S[i]] > (n + 1) / 2) return "";
        }
        for (auto n : um) pq.push({n.second, n.first});
        
        while(pq.size() >= 2) {
            pair<int, char> topA = pq.top(); pq.pop();
            pair<int, char> topB = pq.top(); pq.pop();
            result.push_back(topA.second); 
            if (topA.first > 1) pq.push({topA.first - 1, topA.second});
            result.push_back(topB.second);
            if (topB.first > 1) pq.push({topB.first - 1, topB.second});
        }
        
        if (pq.size() > 0) {
            pair<int, char> top = pq.top(); pq.pop();
            result.push_back(top.second);
        }
        return result;
    }
};
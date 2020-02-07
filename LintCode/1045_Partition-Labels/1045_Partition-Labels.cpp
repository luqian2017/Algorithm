class Solution {
public:
    /**
     * @param S: a string
     * @return: a list of integers representing the size of these parts
     */
    vector<int> partitionLabels(string &S) {
        int len = S.size();
        vector<int> lastPos(26, 0);
        
        int p1 = 0, p2 = 0;
        for (int i = 0; i < len; ++i) {
            lastPos[S[i] - 'a'] = i; 
        }

        vector<int> result;
        int posStart = 0, posEnd = 0;
        while(p1 < len && p2 < len) {
            p2 = lastPos[S[p1] - 'a'];
            posEnd = max(posEnd, p2);

            if (p1 == posEnd) {
                result.push_back(posEnd - posStart + 1);
                posStart = posEnd + 1;
            }
            p1++;
        }
        
        return result;
    } 
};
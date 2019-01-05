class Solution {
public:
    /**
     * @param J: the types of stones that are jewels
     * @param S: representing the stones you have
     * @return: how many of the stones you have are also jewels
     */
    int numJewelsInStones(string &J, string &S) {
        vector<int> jewelsTable(255, 0);
        
        int lenJ = J.size();
        int lenS = S.size();
        if (lenJ == 0 || lenS == 0) return 0;
        
        for (int i = 0; i < lenJ; ++i) {
            jewelsTable[J[i]] = 1;
        }
        
        int result = 0;
        for (int i = 0; i < lenS; ++i) {
            result += jewelsTable[S[i]];
        }
        
        return result;
    }
};
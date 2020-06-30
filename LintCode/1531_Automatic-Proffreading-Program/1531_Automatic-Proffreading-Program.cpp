class Solution {
public:
    /**
     * @param str: The string before proofreading.
     * @return: Return the string after proofreading.
     */
    string automaticProofreadingProgram(string &str) {
        string res = str;
        int len = str.size();
        int p1 = 0, p2 = 0;
        for (int p1 = 0; p1 < len; ++p1) {
            res[p2++] = str[p1];
            
            //AABB
            if ((p2 >= 3 && res[p2 - 1] == res[p2 - 2] && res[p2 - 1] == res[p2 - 3]) ||
            //WOOOOOOOW
            (p2 >= 4 && res[p2 - 1] == res[p2 - 2] && res[p2 -3] == res[p2 - 4])) {
                    p2--;
            }
        }
        
        return res.substr(0, p2);
    }
};
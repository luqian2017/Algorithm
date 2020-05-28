class Solution {
public:
    /**
     * @param s: a string
     * @param t: a string
     * @return: the letter that was added in t
     */
    char findTheDifference(string &s, string &t) {
        int XOR_result = 0;
        for (int i = 0; i < s.size(); ++i) {
            XOR_result ^= s[i];
            XOR_result ^= t[i];
        }
        XOR_result ^= t[t.size() - 1];
        //return 'a' + (XOR_result - 'a');
        return (char)XOR_result;
    }
};
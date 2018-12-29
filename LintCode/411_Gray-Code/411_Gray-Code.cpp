class Solution {
public:
    /**
     * @param n: a number
     * @return: Gray code
     */
    vector<int> grayCode(int n) {
        vector<int> result;
        int len = 1 << n;
       // result.reserve(len);
        for (int i = 0; i < len; ++i) {
            result.push_back(i ^ (i >> 1));
        }
        return result;
    }
};
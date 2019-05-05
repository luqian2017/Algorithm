class Solution {
public:
    /**
     * @param n: An integer
     * @return: a list of combination
     */
    vector<vector<int>> getFactors(int n) {
        vector<int> v;
        vector<vector<int>> vv;
        helper(n, 2, v, vv);
        return vv;
    }

private:
    void helper(int n, int index, vector<int> & v, vector<vector<int>> &vv) {
        if (v.size() > 0) {
            v.push_back(n);
            vv.push_back(v);
            v.pop_back();
        }
        for (int i = index; i <= sqrt(n); ++i) {
            if (n % i == 0) {
                v.push_back(i);
                helper(n / i, i, v, vv);
                v.pop_back();
            }
        }
    }

};
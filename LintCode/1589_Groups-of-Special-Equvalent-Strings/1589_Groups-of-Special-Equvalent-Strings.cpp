class Solution {
public:
    /**
     * @param A: a string array
     * @return: Return the number of groups of special-equivalent strings from A.
     */
    int numSpecialEquivGroups(vector<string> &A) {
        int n = A.size();
        map<pair<vector<int>, vector<int>>, vector<string>> um;  //<{odd, even}, {vector of strings}>
        for (int i = 0; i < n; ++i) {
            int strSize = A[i].size();
            vector<int> odd(26, 0), even(26, 0);
            for (int j = 0; j < strSize; ++j) {
                if (j & 0x1) odd[A[i][j] - 'a']++;
                else even[A[i][j] - 'a']++;
            }
            um[{odd, even}].push_back(A[i]);
        }
        return um.size();        

    }
};
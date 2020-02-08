class Solution {
public:
    /**
     * @param S: The given string S
     * @param T: The given string T
     * @return: any permutation of T (as a string) that satisfies this property
     */
    string customSortString(string &S, string &T) {
        int m = S.size();
        int n = T.size();
        vector<int> counter(26);
        
        for (int i = 0; i < n; ++i) counter[T[i] - 'a']++;
        
        string result;
        for (int i = 0; i < m; ++i) {
            if (counter[S[i] - 'a'] > 0) result = result + string(counter[S[i] - 'a'], S[i]);
        }
        for (int i = 0; i < n; ++i) {
            if (counter[T[i] - 'a'] == 0) result = result + T[i];
        }
        
        return result;
    }
};
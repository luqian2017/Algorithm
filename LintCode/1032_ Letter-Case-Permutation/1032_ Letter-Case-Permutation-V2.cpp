class Solution {
public:
    /**
     * @param S: a string
     * @return: return a list of strings
     */
    vector<string> letterCasePermutation(string &S) {
        int n = S.size();
        if (n == 0) return {""};
        vector<string> result;
        string sol = S;
        helper(S, 0, result);
        return result;
    }

private:
    void helper(string & S, int index, vector<string> & result) {
       result.push_back(S);    
       
       for (int i = index; i < S.size(); ++i) {
           if (isalpha(S[i])) {
                if (S[i] >= 'A' && S[i] <= 'Z') {
                   S[i] += 'a' - 'A';
                }
                else {
                   S[i] -= 'a' - 'A';
                }
               
                helper(S, i + 1, result);
           
                if (S[i] >= 'A' && S[i] <= 'Z') {
                   S[i] += 'a' - 'A';
                }
                else {
                   S[i] -= 'a' - 'A';
                }
           }
       }
    }
    
};
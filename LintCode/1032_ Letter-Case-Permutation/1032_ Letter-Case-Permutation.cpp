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
        helper(S, 0, result);
        return result;
    }

private:
    void helper(string & S, int index, vector<string> & result) {
        if (index == S.size()) {
            result.push_back(S);
            return;
        }
       
       helper(S, index + 1, result);
       if (isalpha(S[index])) {
            if (S[index] >= 'A' && S[index] <= 'Z') {
                S[index] += 'a' - 'A';
            }
            else {
                S[index] -= 'a' - 'A';
            }
            helper(S, index + 1, result);
        }
    }
    
};

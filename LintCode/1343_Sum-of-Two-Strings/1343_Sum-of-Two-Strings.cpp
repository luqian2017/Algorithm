class Solution {
public:
    /**
     * @param A: a string
     * @param B: a string
     * @return: return the sum of two strings
     */
    string SumofTwoStrings(string &A, string &B) {
        string result;
        int len_short = min(A.size(), B.size());
        int len_long = max(A.size(), B.size());
        string str_short, str_long;
        str_short = (A.size() > B.size()) ? B : A;
        str_long = (A.size() > B.size()) ? A : B;
        reverse(str_short.begin(), str_short.end());   
        reverse(str_long.begin(), str_long.end());

        for (int i = 0; i < len_long; ++i) {
            if (i < len_short) {
                string temp = to_string((str_short[i] - '0') + (str_long[i] - '0'));
                result = temp + result;
            } else {
                result = str_long[i] + result;
            }
        }

        return result;
    }
};
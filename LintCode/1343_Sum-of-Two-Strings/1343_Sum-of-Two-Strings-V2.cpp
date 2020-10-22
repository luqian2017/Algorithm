class Solution {
public:
    /**
     * @param A: a string
     * @param B: a string
     * @return: return the sum of two strings
     */
    string SumofTwoStrings(string &A, string &B) {
        string result;

        //always let A be the shorter string
        if (A.size() > B.size()) swap(A, B);
        int len_A = A.size();
        int len_B = B.size();

        int diff = len_B - len_A;
        for (int i = 0; i < len_B; ++i) {
            if (i < diff) {
                result = result + B[i];
            } else {
                result = result + to_string((A[i - diff] - '0') + (B[i] - '0'));  
            }    
        }

        return result;
    }
};
class Solution {
public:
    /**
     * @param A: A positive integer which has N digits, A is a string
     * @param k: Remove k digits
     * @return: A string
     */
    string DeleteDigits(string &A, int k) {
        int N = A.size();
        if (N == 0) return "";
        if (k == 0) return A;
        
        int m = N - k;  // the rest numbers
        string result = "";
        for (int i = 0; i < m; ++i) {
            int pos = 0; 
            char minChar = A[pos];
 
            for (int j = 0; j < A.size() - m + i + 1; ++j) {
                if (A[j] < minChar) {
                    pos = j;
                    minChar = A[j];
               }
            }
            result = result + A[pos];
            A = A.substr(pos + 1);
        }
        
        int posZero = -1;
        for (int i = 0; i < result.size(); ++i) {
            if (result[i] != '0') {
                posZero = i;
                result = result.substr(posZero);
                return result;
            }
        }
        
        return "0";
    }
};
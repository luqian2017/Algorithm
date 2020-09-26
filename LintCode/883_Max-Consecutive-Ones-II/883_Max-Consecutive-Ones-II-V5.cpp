class Solution {
public:
    /**
     * @param nums: a list of integer
     * @return: return a integer, denote  the maximum number of consecutive 1s
     */
    int findMaxConsecutiveOnes(vector<int> &A) {
        int K = 1;
        int n = A.size();
        int i = 0, j = 0;
        for (j = 0; j < n; ++j) {
            if (A[j] == 0) --K;
            //if (K < 0 && A[i++] == 0) ++K;
            if (K < 0) {
                if (A[i] == 0) ++K;
                i++;
            }
          //  cout<<"j="<<j<<" i="<<i<<" K="<<K<<endl;
        }
        return j - i;
    }
};
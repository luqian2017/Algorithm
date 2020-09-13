class Solution {
public:
    /**
     * @param S: a string
     * @return:  return the minimum number of moves
     */
    int MinimumMoves(string &S) {
        int len = S.size();
      //  if (len == 0) return 0;
        int count = 1;
        int result = 0;
        for (int i = 1; i < len; i++) {
            if (S[i] != S[i - 1]) {
                if (count >= 3) result += count / 3;
                count = 1;
            } else {
                count++;
            }
        }
        
        if (count >= 3) result += count / 3;

        return result;
    }
};
class Solution {
public:
    /**
     * @param S: a string
     * @return:  return the minimum number of moves
     */
    int MinimumMoves(string &S) {
        int len = S.size();
        int count_a = 0, count_b = 0;
        int result = 0;
        for (int i = 0; i < len; i++) {
            if (S[i] == 'a') {
                if (count_b >= 3) result += count_b / 3;
                count_b = 0;
                count_a++;
            } else {
                if (count_a >= 3) result += count_a / 3;
                count_a = 0;
                count_b++;
            }
        }
        
        if (count_a > 0) result += count_a / 3;
        else if (count_b > 0) result += count_b / 3;
        
        return result;
    }
};
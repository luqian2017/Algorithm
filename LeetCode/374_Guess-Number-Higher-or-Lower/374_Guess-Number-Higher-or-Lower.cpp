/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int start = 1, end = n;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            int pick = guess(mid);
            if (pick == 0) return mid;
            else if (pick == -1) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if (guess(end) == 0) return end;
        else return start;
    }
};
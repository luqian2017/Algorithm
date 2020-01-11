// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    /**
     * @param n an integer
     * @return the number you guess
     */
    int guessNumber(int n) {
        int start = 1, end = n;
        while(start + 1 < n) {
            int mid = start + (end - start) / 2;
            if (guess(mid) == -1) {
                end = mid;
            } else if (guess(mid) == 1) {
                start = mid;
            } else {
                return mid;
            }
        }
        if (guess(start) == 0) return start;
        return end;
    }
};
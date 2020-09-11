class Solution {
public:
    /**
     * @param X: a integer
     * @param Y: a integer
     * @param nums: a list of integer
     * @return: return the maximum index of largest prefix
     */
    int LongestPrefix(int X, int Y, vector<int> &nums) {
        int len = nums.size();
        int X_count = 0, Y_count = 0;
        int result = -1;

        for (int i = 0; i < len; ++i) {
            if (nums[i] == X) {
                X_count++;
            } else if (nums[i] == Y) {
                Y_count++;
            }

            if (X_count == Y_count && X_count != 0) {
                result = i;
            }
        }

        return result;
    }
};
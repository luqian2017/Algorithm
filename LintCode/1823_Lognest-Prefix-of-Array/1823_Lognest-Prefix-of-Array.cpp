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
        vector<pair<int, int>> prefixes(len, {0, 0}); //<# of X, # of Y>
        int result = -1;

        if (nums[0] == X) {
            prefixes[0] = {1, 0};
        } else if (nums[0] == Y) {
            prefixes[0] = {0, 1};
        }

        for (int i = 1; i < len; ++i) {
            if (nums[i] == X) {
                prefixes[i] = {prefixes[i - 1].first + 1, prefixes[i - 1].second};
            } else if (nums[i] == Y) {
                prefixes[i] = {prefixes[i - 1].first, prefixes[i - 1].second + 1};
            } else {
                prefixes[i] = prefixes[i - 1];
            }

            if (prefixes[i].first == prefixes[i].second && prefixes[i].first != 0) {
                result = i;
            }
        }

        return result;
    }
};
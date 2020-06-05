class Solution {
public:
    /**
     * @param nums: a list of integers
     * @param lower: a integer
     * @param upper: a integer
     * @return: return a integer
     */
    int countRangeSum(vector<int> &nums, int lower, int upper) {
        int n = nums.size();
        multiset<long long> ms;
        long long presums = 0;
        int result = 0;
        ms.insert(0);

        for (int i = 0; i < n; ++i) {
            presums += nums[i];
            result += distance(ms.lower_bound(presums - upper), ms.upper_bound(presums - lower));
            ms.insert(presums);
        }
        
        return result;
    }
};
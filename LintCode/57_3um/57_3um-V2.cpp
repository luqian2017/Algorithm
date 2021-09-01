class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @return: Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int>> threeSum(vector<int> &numbers) {
        int n = numbers.size();
        if (n < 3) return {};
      //  vector<vector<int>> res;
        set<vector<int>> res_set;
        sort(numbers.begin(), numbers.end());
        for (int i = 2; i < n; i++) {
            int start = 0, end = i - 1;
            int target = -numbers[i];
            while (start < end) {
                int sum = numbers[start] + numbers[end];
                if (sum < target) {
                    start++;
                } else if (sum > target) {
                    end--;
                } else {
                    res_set.insert({numbers[start], numbers[end], numbers[i]});
                    start++; end--;
                }
            }
        }
       
        vector<vector<int>> res(res_set.begin(), res_set.end());
        return res;
    }
};
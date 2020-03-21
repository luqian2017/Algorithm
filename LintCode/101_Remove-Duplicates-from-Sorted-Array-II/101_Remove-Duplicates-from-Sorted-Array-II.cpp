class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        int n = nums.size();
        if (n <= 2) return n;
        unordered_map<int, int> um;
        int pos = 0;
        int len = n;
        for (int i = 0; i < n; ++i) {
            um[nums[i]]++;
            if (um[nums[i]] <= 2) {
                nums[pos] = nums[i];
                pos++;
            }
            else {
                len--;
            }
        }
        return len;
    }
};
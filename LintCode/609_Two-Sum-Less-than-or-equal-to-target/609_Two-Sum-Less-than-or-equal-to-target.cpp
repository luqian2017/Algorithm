
class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: an integer
     * @return: an integer
     */
    int twoSum5(vector<int> &nums, int target) {
        int len = nums.size();
        sort(nums.begin(), nums.end());

        int p1 = 0, p2 = len - 1;
        int count = 0;
        while(p1 < p2) {
            int sum = nums[p1] + nums[p2];
            if (sum > target) {
                p2--;
                continue;
            }
            count += p2 - p1;
            p1++; 
        } 
        
        return count;
    }
};


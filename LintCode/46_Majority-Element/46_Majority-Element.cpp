class Solution {
public:
    /*
     * @param nums: a list of integers
     * @return: find a  majority number
     */
    int majorityNumber(vector<int> &nums) {
        int result = 0, count = 0;
        for (auto i : nums) {
            if (count == 0) {
                result = i;
                count++;
            } else if (nums[i] == result) {
                count++;
            } else {
                count--;
            }
        }
        
        return result;
    }
};
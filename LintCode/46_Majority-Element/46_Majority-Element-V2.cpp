class Solution {
public:
    /*
     * @param nums: a list of integers
     * @return: find a  majority number
     */
    int majorityNumber(vector<int> &nums) {
        int N = nums.size();

        int result = 0;
        
        for (int i = 0; i < 32; ++i) {
            int count = 0;
            for (auto n : nums) {
                int digit = (n >> i) & 0x1;
                if (digit == 1) count++;
            }

            if (count > N / 2) result |= (0x1 << i);
        }
        
        return result;
    }
};
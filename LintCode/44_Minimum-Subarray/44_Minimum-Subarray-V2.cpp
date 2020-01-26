class Solution {
public:
    int minSubArray(vector<int> nums) {
        int minSum = nums[0];  // 初始化minSum
        int sum = 0;  

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum < minSum) {
                minSum = sum;  //minSum记录前 i 位元素能够成的最小subArray之和
            }
            if (sum > 0) {   // 因为nums中有负数，所以某一段subArray的sum超过0，则舍弃，重置为0
                sum = 0;
            }
        }
        return minSum;
    }
};
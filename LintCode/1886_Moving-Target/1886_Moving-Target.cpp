class Solution {
public:
    /**
     * @param nums: a list of integer
     * @param target: an integer
     * @return: nothing
     */
    void MoveTarget(vector<int> &nums, int target) {
        int n = nums.size();
        int targetCount = 0;
        int pLeft = n - 1, pRight = n - 1;
        while(pLeft >= 0) {
            if (nums[pLeft] != target) {
                nums[pRight] = nums[pLeft];
                pRight--;
            } else {
                targetCount++;
            }
            pLeft--;
        }
        
        for (int i = 0; i < targetCount; ++i) {
            nums[i] = target;
        }
        return;
    }
};
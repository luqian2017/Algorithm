class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: nothing
     */
    void recoverRotatedSortedArray(vector<int> &nums) {
        int pos = 0;
        int arrayLen = nums.size();
        
        for (int i = 1; i < arrayLen; ++i) {
            if (nums[i] < nums[i - 1]) {
                pos = i;
                break;
            } 
        }
        
        if (pos == 0) return;
        
        reverse(nums, 0, pos - 1);
        reverse(nums, pos, arrayLen - 1);
        reverse(nums, 0, arrayLen - 1);
    }

private:
    void reverse(vector<int> &nums, int start, int end) {
        
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
};
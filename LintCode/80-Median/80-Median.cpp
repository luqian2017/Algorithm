class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the middle number of the array
     */
    int median(vector<int> &nums) {
        int n = nums.size();
        vector<int> orignums;
        //int index = (n & 0x1) ? n / 2 + 1 : n / 2;
        return quickSelect(nums, 0, n - 1, (n + 1) / 2);
        return 0;
    }
private:
    int quickSelect(vector<int> &nums, int start, int end, int k) {
        if (start >= end) return nums[start]; //nums[k];
        int left = start, right = end;
        int pivot = nums[left + (right - left) / 2];
        while (left <= right) {
            while (left <= right && nums[left] < pivot) left++;
            while (left <= right && nums[right] > pivot) right--;
            if (left <= right) {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }
        if (start + k - 1 <= right)
            return quickSelect(nums, start, right, k);
        if (start + k - 1 >= left)
            return quickSelect(nums, left, end, k - (left - start));
        return pivot;
    }
};
class Solution {
public:
    /**
     * @param k: An integer
     * @param nums: An integer array
     * @return: kth smallest element
     */
    int kthSmallest(int k, vector<int> &nums) {
        int n = nums.size();
        if (n == 0 || n < k) return -1;
        return quickSelect(nums, k, 0, n - 1);
    }

private:
    int quickSelect(vector<int> & nums, int k, int start, int end) {
        if (start >= end) return nums[start];
        int left = start, right = end;
        int pivot = nums[(left + right) / 2];
        while(left <= right) {
            while(left <= right && nums[left] < pivot) left++;
            
            while(left <= right && nums[right] > pivot) right--;
            
            if (left <= right) { // do not miss this line
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }
        
        if (start + k - 1 <= right) return quickSelect(nums, k, start, right);
        if (start + k - 1 >= left) return quickSelect(nums, k - (left - start), left, end);
        
        return nums[right + 1];
    }
};
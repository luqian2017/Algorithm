class Solution {
public:
    /**
     * @param nums: an integer array
     * @param k: An integer
     * @return: the top k largest numbers in array
     */
    vector<int> topk(vector<int> &nums, int k) {
        vector<int> result;
        int numSize = nums.size();
        if (numSize < k) return result;
        
        int KthLargestNum = quickSelect(nums, 0, numSize - 1, numSize - k);
        
        for (int i = 0; i < numSize; ++i) {
            if (nums[i] >= KthLargestNum) result.push_back(nums[i]);
        }
        sort(result.rbegin(), result.rend());
        result.resize(k); //in case nums has some duplicate elements
        return result;
    }
    
private:
    int quickSelect(vector<int> &nums, int start, int end, int k) {
        if (start >= end) return nums[k];
        
        int left = start, right = end;
        int pivot = nums[left + (right - left) / 2];
        
        while (left <= right) {
            while(left <= right && nums[left] < pivot) left++;
            
            while(left <= right && nums[right] > pivot) right--;
            
            if (left <= right) {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                left++;
                right--;
            }
        }    
        
        if (start + k -1 <= right) 
            return quickSelect(nums, start, right, k);
            
        if (start + k - 1 >= left)
            return quickSelect(nums, left, end, k - (left - start));
                
        return pivot;
    }
};
class Solution {
public:
    /**
     * @param nums: the given k sorted arrays
     * @return: the median of the given k sorted arrays
     */
    double findMedian(vector<vector<int>> &nums) {
        if (nums.size() == 0) return 0;
        
        int totalCount = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            totalCount += nums[i].size();    
        }
        
        if (totalCount & 0x1) {
        //odd number
            return findKthLargestNumber(nums, totalCount / 2 + 1);
        } else {
        //even number
            return findKthLargestNumber(nums, totalCount / 2) / 2.0 + 
                   findKthLargestNumber(nums, totalCount / 2 + 1) / 2.0;

        }
    }
    
    int findKthLargestNumber(vector<vector<int>> &nums, int k) {
        int start  = 0;
        int end = INT_MAX;
        
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (getGTECount(nums, mid) >= k) {
                start = mid;
            } else {
                end = mid;
            }
        }    
        
        if (getGTECount(nums, start) >= k) return start;
        
        return end;
    }
    
    int getGTECount(vector<vector<int>> &nums, int val) {
        int count = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            count += getGTECount(nums[i], val);
        }
        
        return count;
    }
    
    int getGTECount(vector<int> &nums, int val) {
        if (nums.size() == 0) return 0;
        int start = 0;
        int end = nums.size() - 1;
        
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] >= val) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if (nums[start] >= val) return nums.size() - start;
        if (nums[end] >= val) return nums.size() - end;
        return 0;
    }
};
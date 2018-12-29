class Solution {
public:
    /*
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int n, vector<int> &nums) {
        if (nums.empty()) return -1;
        return quickSelect(nums, 0, nums.size()-1, n);
    }

private:
    int quickSelect(vector<int> &nums, int start, int end, int k) {
        if (start>=end) return nums[start];
        
        int i=start, j=end;
        int pivot=nums[start+(end-start)/2];
        
        while (i<=j) {
            while (i<=j && nums[i]>pivot) i++;
            while (i<=j && nums[j]<pivot) j--;
            
            if (i<=j) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
      
       if (start+k-1<=j) 
           return quickSelect(nums, start, j, k);
       
       if (start+k-1>=i)
           return quickSelect(nums, i, end, k-(i-start));
    
       return nums[j+1];    //just return the pivot
    }    
    
};
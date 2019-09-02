class Solution {
public:
    /**
     * @param nums: an integer array
     * @param k: An integer
     * @return: the top k largest numbers in array
     */
    vector<int> topk(vector<int> &nums, int k) {
        int n = nums.size();
        if (n == 0 || k > n) return vector<int>();
        vector<int> result;
        
        int pivot = quickSelect(nums, 0, n - 1, k);

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > pivot) result.push_back(nums[i]);
        }
        
        while(result.size() < k) {
            result.push_back(pivot);
        }
        sort(result.rbegin(), result.rend());
        return result;
    }
    
private:
    int quickSelect(vector<int> &nums, int start, int end, int k) {

        if (start == end) return nums[start]; //note it is not nums[k]
        
        int i = start, j = end;
        
        int pivot = nums[i + (j - i) / 2];
        
        while (i <= j) {
            while(i <= j && nums[i] > pivot) {
                i++;
            }
            while(i <= j && nums[j] < pivot) {
                j--;
            }
            if (i <= j) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
        
        if (j - start + 1 >= k) {
            return quickSelect(nums, start, j, k);
        }
        
        if (i - start + 1 <= k) {
            return quickSelect(nums, i, end, k - (i - start));
        }
        
        return pivot;
        //return nums[j + 1];
    }
};
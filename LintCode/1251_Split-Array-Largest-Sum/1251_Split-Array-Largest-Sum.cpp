class Solution {
public:
    /**
     * @param nums: a list of integers
     * @param m: an integer
     * @return: return a integer
     */
    int splitArray(vector<int> &nums, int m) {
        int n = nums.size();
        if (n == 0) return 0;
        int max_elem = *max_element(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < n; ++i) sum += nums[i];
        int start = max_elem, end = sum;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (can_split(nums, m, mid)) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if (can_split(nums, m, start)) return start;
        if (can_split(nums, m, end)) return end;
    }

private:
    bool can_split(vector<int> &nums, int m, int thresh) {
        int n = nums.size();
        int index = 0, sum = 0;
        int num_subarrs = 1;
        
        while (index < n) {
            sum += nums[index];
            if (sum > thresh) {
                sum = nums[index];
                num_subarrs++; 
                if (num_subarrs > m) return false;
            }
            index++;
        }
        
     //   if (num_subarrs == m) return true;   //错误
     //   return false;                        //错误
        return true;
    }

};
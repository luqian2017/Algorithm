class Solution {
public:
    /**
     * @param nums: the input array
     * @param target: the target number
     * @return: return the target pair
     */
    vector<vector<int>> twoSumVII(vector<int> &nums, int target) {
        int n = nums.size();
       
        vector<vector<int>> res;
        for (int i = 0; i < n; ++i) {
            if (nums[i] >= 0 && minPosIndex < 0) {
                minPosIndex = i;
            }
            if (nums[i] < 0 && maxNegIndex < 0) {
                maxNegIndex = i;
            }
            if (minPosIndex >= 0 && maxNegIndex >= 0) break;
        }
        
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] >= 0 && maxPosIndex < 0) {
                maxPosIndex = i;
            }
            if (nums[i] < 0 && minNegIndex < 0) {
                minNegIndex = i;
            }
            if (maxPosIndex >= 0 && minNegIndex >= 0) break;
        }

        start = minNegIndex >= 0 ? minNegIndex : minPosIndex;
        end = maxPosIndex >= 0? maxPosIndex : maxNegIndex;
        int origStart = start, origEnd = end;

        while ((start != origEnd || end != origStart) && start >= 0 && start < n && end >= 0 && end < n) {
            int sum = nums[start] + nums[end];
            if (sum < target) {
                moveStart(nums);
            } else if (sum > target) { 
                moveEnd(nums);
            } else {
                if (start < end) res.push_back({start, end});
                moveStart(nums);
                moveEnd(nums);
            }
        }
        
        if (start == origEnd && end == origStart && nums[start] + nums[end] == target && start < end) res.push_back({start, end});
        return res;
    }
private:
    int start, end;
    int minNegIndex = -1, maxNegIndex = -1, minPosIndex = -1, maxPosIndex = -1;

    void moveStart(vector<int> &nums) {
        int n = nums.size();
        if (nums[start] < 0 && nums[start] < nums[maxNegIndex]) {
            do {
                start--;
                if (nums[start] < 0) break;
            } while (start >= 0);
        } else if (nums[start] < 0 && nums[start] == nums[maxNegIndex]) {
            start = minPosIndex;
        } else if (minPosIndex >= 0) { //may not need  if (minPosIndex >= 0) 
            do {
                start++;
                if (nums[start] >= 0) break;
            } while (start < n);
        }
    }
    
    void moveEnd(vector<int> &nums) {
        int n = nums.size();
        if (nums[end] >= 0 && nums[end] > nums[minPosIndex]) {
            do {
                end--;
                if (nums[end] >= 0) break;
            } while (end >= 0);
        } else if (nums[end] >= 0 && nums[end] == nums[minPosIndex]) {
            end = maxNegIndex;
        } else if (maxNegIndex >= 0){ //may not need if (maxNegIndex >= 0)
            do {
                end++;
                if (nums[end] < 0) break;
            } while (end < n);
        }
    }
};
class Solution {
public:
    /**
     * @param A: An integer array
     * @param queries: The query list
     * @return: The number of element in the array that are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        int n = A.size();
        int m = queries.size();
        if (m <= 0) return vector<int>();
        if (n <= 0) return vector<int>(m, 0);

        sort(A.begin(), A.end());
        
        vector<int> result;
        for (int i = 0; i < m; ++i) {
            result.push_back(findPos(A, queries[i]));
        }
        
        return result;
    }
    
private:
    int findPos(vector<int> &nums, int target) {
        int n = nums.size();
        int start = 0, end = n - 1;
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] >= target) {
                end = mid;
            } else if (nums[mid] < target) {
                start = mid;
            }
        }

        if (nums[end] == target) {
            if (nums[start] == target) return start;
            return end;   
        }
        if (nums[end] < target) return end + 1;
        if (nums[start] == target) return start;
        if (nums[start] < target) return start + 1;
    }
};
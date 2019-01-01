class Solution {
public:
    /**
     * @param nums: an array of integers
     * @param k: an integer
     * @return: the number of unique k-diff pairs
     */
    int findPairs(vector<int> &nums, int k) {
        
        int result = 0;
        int len = nums.size();
        if (len <= 1) return 0;
        
        sort(nums.begin(),  nums.end());
        int p1 = 0, p2 = 1; // p2 is ahead of p1
        set<pair<int, int>> s;
        if (k < 0) k = -k;  //important!
        
        while(p1 < p2) {
            int diff = nums[p2] - nums[p1]; 
            if (diff == k) {
                s.insert(make_pair(min(nums[p1], nums[p2]), max(nums[p1], nums[p2])));
                p1++; p2++;
            } else if (diff < k) {
                p2++;
            } else {
                p1++;
            }
        }
        
        return s.size();
    }
};
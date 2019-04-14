class Solution {
public:
    /**
     * @param nums: an array of integers
     * @return: the number of unique integers
     */
    int deduplication(vector<int> &nums) {
        int n = nums.size();
        if (n <= 1) return n;
        unordered_set<int> us;
        int count = 0;
        int p1 = 0, p2 = n - 1;
        while(p1 <= p2) {
            
            if (us.find(nums[p1]) == us.end()) {
                us.insert(nums[p1]);
                count++;
                p1++;
            } else {
                while(us.find(nums[p2]) != us.end() && (p1 <= p2)) {
                    p2--;
                }
                if (p1 < p2) {
                    us.insert(nums[p2]);
                    swap(nums[p1], nums[p2]);
                    count++;
                    p1++; p2--;
                }
            }
        }
    
        return count;
    }
};
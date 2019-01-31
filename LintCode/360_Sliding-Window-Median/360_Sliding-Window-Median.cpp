class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer
     * @return: The median of the element inside the window at each moving
     */
    vector<int> medianSlidingWindow(vector<int> &nums, int k) {
        
        
        int len = nums.size();
        
        if ((len < k) || (k == 0)) return vector<int>();
        
        vector<int> result;
        
        multiset<int> smallSet, largetSet;
        
        for (int i = 0; i < len; ++i) {
            
            //make sure sum of smallSet.size() and largetSet.size() not exceeds k 
            if (i >= k) {
                //remove nums[i - k], sliding window 
                if (smallSet.find(nums[i - k]) != smallSet.end()) smallSet.erase(smallSet.find(nums[i - k]));
                else largetSet.erase(largetSet.find(nums[i - k]));
                //if (largetSet.find(nums[i - k]) != largetSet.end()) largetSet.erase(nums[i - k]);
                //else smallSet.erase(nums[i - k]);
            }
            
            if (smallSet.size() <= largetSet.size()) { //try to insert into smallSet first
                if (largetSet.empty() || nums[i] <= *largetSet.begin()) {
                    smallSet.insert(nums[i]);
                } else {
                    smallSet.insert(*largetSet.begin());
                    largetSet.erase(largetSet.begin());
                    largetSet.insert(nums[i]);
                }
            } else { //try to insert into largetSet first
                //use .rbegin() to point to the last element, not .end() !!!   
                if (smallSet.empty() || nums[i] >= *smallSet.rbegin()) {
                    largetSet.insert(nums[i]);
                } else {
                    largetSet.insert(*smallSet.rbegin());
                    smallSet.erase(--smallSet.end());
                    smallSet.insert(nums[i]);
                }
            }
            
            if (i >= k - 1) {
                //int num = (k & 0x1) ? *smallSet.rbegin() : (*smallSet.rbegin() + *largetSet.begin()) / 2;
                result.push_back(*smallSet.rbegin());
            }
            
        }
        
        return result;
    }
};
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: the median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        int len = nums.size();
        if (len == 0) return vector<int>();
        
        //top half in minHeap, bottom half in maxHeap
        multiset<int> smallSet, largeSet;
        
        vector<int> result;
        
        for (int i = 0; i < len; ++i) {
            //try to insert the number to the set with smaller size
            if (smallSet.size() <= largeSet.size()) { //smallSet has smaller size
                if (largeSet.empty() || nums[i] <= *largeSet.begin()) {
                    smallSet.insert(nums[i]);
                } else {
                    smallSet.insert(*largeSet.begin());
                    largeSet.erase(largeSet.begin());  //note: do not use *largeSet.begin() as it may delete multiple number with the same value;
                    largeSet.insert(nums[i]);
                }
            } else { //largeSet has smaller size
               // if (smallSet.empty() || nums[i] >= *largeSet.begin()) {
                if (smallSet.empty() || nums[i] >= *smallSet.rbegin()) {
                    largeSet.insert(nums[i]);
                } else {
                    largeSet.insert(*smallSet.rbegin());
                    //smallSet.erase(smallSet.rbegin()); //the parameter of erase should be iterator (rbegin is reverse iterator)
                    smallSet.erase(--smallSet.end());  //important!!!
                    smallSet.insert(nums[i]);
                }
            }
            result.push_back(*smallSet.rbegin());
        }
        return result;
    }
};
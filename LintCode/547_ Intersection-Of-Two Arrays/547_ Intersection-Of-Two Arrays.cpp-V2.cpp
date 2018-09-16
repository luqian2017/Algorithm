class Solution {
public:
    /**
     * @param nums1: an integer array
     * @param nums2: an integer array
     * @return: an integer array
     */
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        
        vector<int> result;
        if ((nums1.size() == 0) || (nums2.size() == 0)) return result;
        
        unordered_set<int> s(nums1.begin(), nums1.end());
        for (auto i : nums2) {
            if (s.find(i) != s.end()) {
                s.erase(i);
                result.push_back(i);
            }
        }
        
        sort(result.begin(), result.end());
        return result;
    }
};
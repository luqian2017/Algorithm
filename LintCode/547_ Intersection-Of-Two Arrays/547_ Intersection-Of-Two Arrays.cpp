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
        
        set<int> s;
        for (int i = 0; i < nums1.size(); ++i) {
            s.insert(nums1[i]);
        }
        
        set<int> noDup;
        for (int i = 0; i < nums2.size(); ++i) {
            if (s.find(nums2[i]) != s.end()) noDup.insert(nums2[i]);
        }
        
        for (auto i : noDup) result.push_back(i);
        return result;
    }
};
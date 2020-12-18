class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> s;
        for (auto n : nums1) {
            s.insert(n);
        }
        for (auto n: nums2) {
            if (s.find(n) != s.end()) res.push_back(n);
            s.erase(n);
        }
        return res;
    }
};
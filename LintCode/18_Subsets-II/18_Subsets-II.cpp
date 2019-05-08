class Solution {
public:
    /**
     * @param nums: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> vv;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        unordered_map<int, int> um; //number, count
        for (auto i : nums) {
            if (um.find(i) == um.end()) {
                um[i] = 1;
            } else {
                um[i]++;
            }
           
        }
        
        queue<vector<int>> q;
        q.push({});  //push {}

        while(!q.empty()) {
            vector<int> v = q.front();
            q.pop();
            vv.push_back(v);
            
            unordered_map<int, int> um_v;
            for (auto i : v) {
                if (um_v.find(i) == um_v.end()) {
                    um_v[i] = 1;
                } else {
                    um_v[i]++;
                }
            }

            for (int i = 0; i < n; ++i) {
                if (v.size() == 0 ||
                    v.back() < nums[i] ||
                   // (v.back() == nums[i] && index <= i)) {
                //    ((v.back() == nums[i]) && (i == v.size()))) {
                    ((v.back() == nums[i]) && (um_v[nums[i]] < um[nums[i]]))) {
                    vector<int> v2 = v;
                    v2.push_back(nums[i]);
                    if (q.back() != v2) {
                        q.push(v2);
                    }
                }
            }

        }
        
        return vv;
    }
};
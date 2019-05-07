class Solution {
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> vv;
        int n = nums.size();

        queue<vector<int>> q;
        q.push({});  //push {}
        
        while(!q.empty()) {
            vector<int> v = q.front();
            q.pop();
            vv.push_back(v);
            
            for (int i = 0; i < n; ++i) {
                if (v.size() == 0 || v.back() < nums[i]) {
                    vector<int> v2 = v;
                    v2.push_back(nums[i]);
                    q.push(v2);
                }
            }
        }
        
        return vv;
    }
};
class Solution {
public:
    /**
     * @param nums: an integer array
     * @return: all the different possible increasing subsequences of the given array
     */
    vector<vector<int>> findSubsequences(vector<int> &nums) {
        vector<vector<int> > vv;
        vector<int> v;

        helper(nums, 0, v, vv);
        return vv;
    }
    

private:
    void helper(vector<int> &nums, int index, vector<int> &v, vector<vector<int> > &vv) {
        if (index == nums.size()) {
            if (s.find(v)==s.end()) {
               if (v.size()>=2) {
                    vv.push_back(v);
                    s.insert(v);
                }
            }
            return;
        }
    
        if (index<nums.size()) {
            if (v.size()==0 || (nums[index] >= v[v.size()-1])) {
                v.push_back(nums[index]);
                helper(nums, index + 1, v, vv);
                v.pop_back();
                helper(nums, index + 1, v, vv);
            } else if (nums[index] < v[v.size()-1]) {  //if does not meet, keep current v, continue the dfs
                helper(nums, index + 1, v, vv);
            }

        }
    }
    
    set<vector<int> > s;

};
class Solution {
public:
    Solution(vector<int> nums): v(nums) {}
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return v;
    }
    
    /** Returns a random shuffling of the array. */
    #if 0
    vector<int> shuffle() {
        vector<int> res = v;
        for (int i = 0; i < res.size(); ++i) {
            int t = i + rand() % (res.size() - i);
            swap(res[i], res[t]);
        }
        return res;
    }
    #endif
    
    vector<int> shuffle() {
        vector<int> res = v;
        int n = v.size();
        for (int i = n - 1; i >= 0; --i) {
            int t = rand() % (i + 1);
            swap(res[i], res[t]);
        }
        return res;
    }
    
private:
    vector<int> v;
};
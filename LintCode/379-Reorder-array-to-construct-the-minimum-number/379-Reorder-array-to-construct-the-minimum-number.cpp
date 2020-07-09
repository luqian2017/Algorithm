class compare {
public:
    bool operator() (const string & a, const string & b) {
        string ab = a + b;
        string ba = b + a;
        return ab < ba;
    }
} cmp;


class Solution {
public:
    /**
     * @param nums: n non-negative integer array
     * @return: A string
     */
    string minNumber(vector<int> &nums) {
        int len = nums.size();
        vector<string> strs(len);

        for (int i = 0; i < len; ++i) {
            strs[i] = to_string(nums[i]);
        }
        
        sort(strs.begin(), strs.end(), cmp);
        
        string result;
        for (int i = 0; i < len; ++i) {
            result += strs[i];
        }
        
        int non_zero_pos = 0;
        for (int i = 0; i < result.size(); ++i) {
            if (result[i] != '0') return result.substr(i);
        }
        
        return "0";        
    }
};
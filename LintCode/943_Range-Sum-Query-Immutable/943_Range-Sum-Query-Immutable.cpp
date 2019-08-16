class NumArray {
public:
    NumArray(vector<int> nums) {
        int n = nums.size();
        if (n == 0) return;
        presums.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            presums[i] = presums[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int i, int j) {
        return presums[j + 1] - presums[i];
    }
private:
    vector<int> presums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
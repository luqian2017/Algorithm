class NumArray {
public:
    NumArray(vector<int> nums) : len(nums.size()) {
        sums.resize(len, 0);
        delta.resize(len, 0);
        sums[0] = nums[0];
        for (int i = 1; i < len; ++i) {
            sums[i] = sums[i - 1] + nums[i];
        }
    }
    
    void update(int i, int val) {
        if (i > 0) {
            delta[i] = val + sums[i - 1] - sums[i];
        } else {
            delta[i] = val - sums[i];
        }
        for (int m = i; m < len; ++m) {
            sums[m] += delta[i];
        }
    }
    
    int sumRange(int i, int j) {
    
        if (i > 0) {
            return sums[j] - sums[i - 1];
        } else {
            return sums[j]; 
        }
    }

private:
    vector<int> sums;
    vector<int> delta;
    int len;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
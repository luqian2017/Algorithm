class NumArray {
public:
    NumArray(vector<int> nums) : A(nums), len(nums.size()) {
        C.resize(len + 1);
        for (int i = 0; i < len; ++i) {
            add(i, A[i]);
        }
    }
    
    void update(int i, int val) {
        add(i, val - A[i]);
        A[i] = val;   
    }
    
    int sumRange(int i, int j) {
        return sum(j) - sum(i - 1);
    }

private:
    vector<int> C;
    vector<int> A;
    int len;
    
    int lowbit(int x) {
        return x & -x;
    }
    
    void add(int x, int val) {
        x++;
        for (int i = x; i <= len; i += lowbit(i)) {
            C[i] += val;
        }
    }
    
    int sum(int x) {
        int result = 0;
        x++;
        for (int i = x; i > 0; i -= lowbit(i)) {
            result += C[i];
        }
        return result;
    }
    
    
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
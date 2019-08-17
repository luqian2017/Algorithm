class NumArray {
public:
    NumArray(vector<int> nums) {
        len = nums.size();
        A = nums;
        C.resize(len + 1, 0);
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
    vector<int> C, A;
    int len;

    int lowbit(int x) {
        return x & (-x);
    }
    
    void add(int x, int val) {
        x++;
        for (int i = x; i <= len; i += lowbit(i)) {
        //for (int i = len; i >= x; i -= lowbit(i)) {
            C[i] += val;
        }
    }
    
    int sum(int x) {
        x++;
        int result = 0;
       // for (int i = 1; i <= x; i += lowbit(i)) {
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
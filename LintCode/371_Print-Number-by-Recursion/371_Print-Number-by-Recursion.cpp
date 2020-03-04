class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     * 一共递归n层， 每层处理数字10^(n-1) 到 10^n - 1， 即所有的n位数
     */
    vector<int> numbersByRecursion(int n) {
        vector<int> result;
        num(n, 0, result);
        return result;
    }
    void num(int n, int ans, vector<int> &result){
        if(n == 0){
            if(ans > 0){
                result.push_back(ans);
            }
            return;
        }
        for(int i = 0; i <= 9; i ++){
            num(n - 1, ans * 10 + i, result);
        }
    }
};
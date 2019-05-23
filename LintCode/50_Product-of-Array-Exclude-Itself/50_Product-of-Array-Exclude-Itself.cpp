class Solution {
public:
    /*
     * @param nums: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        int N = nums.size();
        
        if (N == 0) return vector<long long>();
        if (N == 1) return vector<long long>(1, 1);
        
        vector<long long> result(N, 0);
        
        vector<long long> fromBeginArr(N, 1);
        long long fromBeginProd = 1;
        for (int i = 0; i < N; ++i) {
            fromBeginProd *= nums[i];
            fromBeginArr[i] = fromBeginProd;
        }
        
        vector<long long> fromEndArr(N, 1);
        long long fromEndProd = 1;
        for (int i = 0; i < N; ++i) {
            fromEndProd *= nums[N - i - 1];
            fromEndArr[i] = fromEndProd;
        }
        
        result[0] = fromEndArr[N - 2];
        result[N - 1] = fromBeginArr[N - 2];
        
        for (int i = 1; i < N - 1; ++i) {
            result[i] = fromBeginArr[i - 1] * fromEndArr[N - 2 - i];    
        }
        
        return result;
    }
};
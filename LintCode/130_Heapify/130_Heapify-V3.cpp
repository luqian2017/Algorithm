class Solution {
public:
    /*
     * @param A: Given an integer array
     * @return: nothing
     */
    void heapify(vector<int> &A) {
        int n = A.size();
        vector<int> B(n + 1, 0);
        
        for (int i = 1; i <= n; ++i) {
            B[i] = A[i - 1];
            shiftup(B, i);
        }
        
        for (int i = 1; i <= n; ++i) {
            A[i - 1] = B[i];
        }
    }
    
private:
    void shiftup(vector<int> & nums, int pos) {
        while(pos > 1) {
            if (nums[pos / 2] > nums[pos]) {
                swap(nums[pos / 2], nums[pos]);
                pos /= 2;
            } else {
                break;
            }
        }
    }
    


};
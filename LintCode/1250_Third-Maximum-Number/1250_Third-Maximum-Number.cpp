class Solution {
public:
    /**
     * @param nums: the array
     * @return: the third maximum number in this array
     */
    int thirdMax(vector<int> &nums) {
        int n = nums.size();

        int top0, top1, top2;
        
        top0 = INT_MIN, top1 = INT_MIN, top2 = INT_MIN;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > top0) {
                top2 = top1;
                top1 = top0;
                top0 = nums[i];
            } else if (nums[i] > top1 && nums[i] < top0) {
                top2 = top1;
                top1 = nums[i];
            } else if (nums[i] > top2 && nums[i] < top1) {
                top2 = nums[i];
            }
        }
        //cout<<"top0="<<top0<<" top1="<<top1<<" top2="<<top2<<endl;
        if (n < 3) return top0;
        if (top2 == top1) return top0;
        return top2;
    }
};
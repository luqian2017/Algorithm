class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;
        int leftMaxHigh = 0, rightMaxHigh = 0;
        int left = 0, right = n - 1;
        int res = 0;
        while (left < right) {
            leftMaxHigh = max(leftMaxHigh, height[left]);
            rightMaxHigh = max(rightMaxHigh, height[right]);
            
            if (leftMaxHigh < rightMaxHigh) {
                res += leftMaxHigh - height[left];    
                left++;
            } else {
                res += rightMaxHigh - height[right];
                right--;
            }
        }
        return res;
    }
};
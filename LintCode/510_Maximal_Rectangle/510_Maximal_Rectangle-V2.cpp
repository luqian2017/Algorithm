class Solution {
public:
    /**
     * @param matrix: a boolean 2D matrix
     * @return: an integer
     */
    int maximalRectangle(vector<vector<bool>> &matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        int maxArea = 0;        

        vector<int> height(n, 0);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i > 0) && (matrix[i][j] > 0) && (height[j] > 0)){
                    height[j] += matrix[i][j];
                } else {
                    height[j] = matrix[i][j];
                }
            }
            maxArea = max(maxArea, maximalRectangle(height));     
        }

        return maxArea;
    }
    
private:
    int maximalRectangle(vector<int> &nums) {
        int len = nums.size();
        if (len == 0) return 0;
        
        int maxArea = 0;
        vector<int> nums2 = nums;
        nums2.push_back(-1);

        stack<int> monoIncStack;

        for (int i = 0; i <= len; ++i) {
            while (!monoIncStack.empty() && (nums2[i] < nums[monoIncStack.top()])) {
                int top = monoIncStack.top();
                monoIncStack.pop();
                int h = nums2[top];
                int w = monoIncStack.empty() ? i : i - monoIncStack.top() - 1;  //not w = i - top - 1
                maxArea = max(maxArea, h * w);        
            }
            monoIncStack.push(i);
        }
        return maxArea;
    }
};

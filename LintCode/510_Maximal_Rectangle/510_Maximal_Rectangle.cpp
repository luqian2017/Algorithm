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
        
        vector<vector<int>> height(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i > 0) && (matrix[i][j] > 0) && (height[i - 1][j] > 0)){
                    height[i][j] = height[i - 1][j]  + matrix[i][j];
                } else {
                    height[i][j] = matrix[i][j];
                }
            }
        }
        
        int maxArea = 0;
        
        for (int i = 0; i < m; ++i) {
            maxArea = max(maxArea, maximalRectangle(height[i]));     
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
        cout<<endl;
        return maxArea;
    }
};
class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        int len = height.size();
        if (len == 0) return 0;
        
        int maxArea = 0;
        vector<int> height2 = height;
        height2.push_back(-1);
        
        stack<int> monoIncStack; // mono increasing stack

        for (int i = 0; i <= len; ++i) {
            while(!monoIncStack.empty() && 
                  (height2[monoIncStack.top()] >= height2[i])) {
                
                int top = monoIncStack.top();
                monoIncStack.pop();
                int h = height2[top];
                int w = monoIncStack.empty() ? i : i - monoIncStack.top() - 1; 
                //note it is not i - top - 1;
            
                maxArea = max(maxArea, h * w);
            }
            
            monoIncStack.push(i);
        }
        
        return maxArea;
    }
};
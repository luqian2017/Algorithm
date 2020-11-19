class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> mono_inc_stk;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        
        for (int i = 0; i < heights.size(); ++i) {
            while(!mono_inc_stk.empty() && heights[i] < heights[mono_inc_stk.top()]) {
                int tmp = mono_inc_stk.top();
                mono_inc_stk.pop();
                res = max(res, heights[tmp] * (i - mono_inc_stk.top() - 1));
            }
            mono_inc_stk.push(i);
        }
        return res;        
    }
};
class Solution {
public:
    /**
     * @param matrix: a boolean 2D matrix
     * @return: an integer
     */
    int maximalRectangle(vector<vector<bool>> &matrix) {
        int nRow = matrix.size();
        if (nRow == 0) return 0;
        int nCol = matrix[0].size();
        vector<int> heights(nCol, 0);
        int maxArea = 0;
        for (int i = 0; i < nRow; i++) {
            for (int j = 0; j < nCol; j++) {
                if (matrix[i][j] == 0) {
                    heights[j] = 0;
                } else {
                    heights[j] = heights[j] + 1;
                }
            }
            maxArea = max(maxArea, maxRectArea(heights));
        }
        return maxArea;
    }
private:
    int maxRectArea(vector<int> &heights) {
        stack<int> s;
        vector<int> heights2(heights);
        heights2.push_back(-1);
        heights2.insert(heights2.begin(), -1);
        int maxArea = 0;
        for (int i = 0; i < heights2.size(); ++i) {
            while(!s.empty() && heights2[s.top()] > heights2[i]) {
                int oldTop = heights2[s.top()];
                s.pop();
                maxArea = max(maxArea, oldTop * (i - s.top() - 1));
            }
            s.push(i);
        }
        return maxArea;
    }
};
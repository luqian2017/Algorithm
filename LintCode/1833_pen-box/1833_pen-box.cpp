class Solution {
public:
    /**
     * @param boxes: number of pens for each box
     * @param target: the target number
     * @return: the minimum boxes
     */
    int minimumBoxes(vector<int> &boxes, int target) {
        int n = boxes.size();
        if (n == 0) return 0;
        vector<int> presums(n + 1, 0);
        int res = INT_MAX / 3;
        
        for (int i = 1; i <= n; ++i) {
            presums[i] = presums[i - 1] + boxes[i - 1];
        }

        vector<int> left_min(n + 1, INT_MAX / 3); //left_min[i] is the min length of boxes[0..i] (left->right)
        int left = 0, right = 1;
        for (right = 1; right <= n; ++right) {
            while (left < right && presums[right] - presums[left] > target) {
                left++;
            }
            if (presums[right] - presums[left] == target) {
                left_min[right] = right - left;
            }
            left_min[right] = min(left_min[right - 1], left_min[right]);
        }
        

        vector<int> right_min(n + 1, INT_MAX / 3); //right_min[i] is the min length of boxes[i..n-1] (right->left)
        right = n;
        for (left = n - 1; left > 0; --left) {
            while(left < right && presums[right] - presums[left] > target) {
                right--;
            }
            if (presums[right] - presums[left] == target) {
                right_min[left] = right - left;
                res = min(res, left_min[left] + right_min[left]);
            }
            right_min[left] = min(right_min[left + 1], right_min[left]);
        }
        
        return res > n ? -1 : res;
    }
};
class Solution {
public:
    /**
     * @param target: the target
     * @param array: an array
     * @return: the closest value
     */
    int closestTargetValue(int target, vector<int> &array) {
        int len = array.size();
        int p1 = 0, p2 = len - 1;
        int maxV = INT_MIN;
        
        sort(array.begin(), array.end());
        if (array[0] > target) return -1;
        
        while (p1 < p2) {
            int sum = array[p1] + array[p2];
            if (sum > target) p2--;
            else {
                p1++;
                maxV = max(maxV, sum);
            }
        }
        
        return maxV;
    }
};
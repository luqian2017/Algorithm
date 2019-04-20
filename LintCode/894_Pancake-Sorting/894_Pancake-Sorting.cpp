class Solution {
public:
    /**
     * @param array: an integer array
     * @return: nothing
     */
    void pancakeSort(vector<int> &array) {
        int n = array.size();
        if (n <= 1) return;
        
        int curLen = n;
        while (curLen > 1) {
            int max = array[0], maxIndex = 0;
            for (int i = 1; i < curLen; ++i) {
                if (max < array[i]) {
                    max = array[i];
                    maxIndex = i;
                }
            }
            FlipTool::flip(array, maxIndex);
            FlipTool::flip(array, curLen - 1);
            curLen--;
        }
    }
};
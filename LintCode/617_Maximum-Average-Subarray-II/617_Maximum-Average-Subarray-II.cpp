class Solution {
public:
    /**
     * @param nums: an array with positive and negative numbers
     * @param k: an integer
     * @return: the maximum average
     */
    double maxAverage(vector<int> &nums, int k) {
        int len = nums.size();
        if (len == 0 || len < k) return 0;
       
        vector<double> prefixSum(len, 0);
        prefixSum[0] = nums[0];
        for (int i = 1; i < len; ++i) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        double maxAve = prefixSum[k - 1] / k;
        
        for (int i = k - 1; i < len; ++i) {
            for (int j = 0; j <= i - k + 1; ++j) {
               if (j == 0) {
                    int tempLen = i + 1;
                    if (maxAve * tempLen < prefixSum[i]) {
                        maxAve = prefixSum[i] / tempLen;
                    }
                }
                else {
                    double tempSum = prefixSum[i] - prefixSum[j - 1];
                    int tempLen = i - j + 1;
                    if (maxAve * tempLen < tempSum) {
                        maxAve = tempSum / tempLen;
                    }
                }

            }
        }
        return maxAve;
    }
};
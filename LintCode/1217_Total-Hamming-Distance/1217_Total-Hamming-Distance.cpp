class Solution {
public:
    /**
     * @param nums: the gievn integers
     * @return: the total Hamming distance between all pairs of the given numbers
     */
    int totalHammingDistance(vector<int> &nums) {
        int n = nums.size();
        int totalDist = 0;
        int intSizeInBits = sizeof(int) * 8;
        for (int i = 0; i < intSizeInBits; ++i) {
            int total1Count = 0, total0Count = 0;    
            for (int j = 0; j < n; ++j) {
                total1Count += (nums[j] & (0x1 << i)) ? 1 : 0;
                //total1Count += (nums[j] >> i) & 0x1;
            }
            total0Count = n - total1Count;
            totalDist += total1Count * total0Count;
        }
        
        return totalDist;
    }
};
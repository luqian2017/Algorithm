struct bucketType {
    int count;
    int minNum;
    int maxNum;
    bucketType(int c = 0, int minV = INT_MAX, int maxV = 0) : count(c), minNum(minV), maxNum(maxV) {}
};

class Solution {
public:
    /**
     * @param nums: an array of integers
     * @return: the maximun difference
     */
    int maximumGap(vector<int> &nums) {
        int n = nums.size();
        if (n < 2) return 0;
        
        int minV = INT_MAX, maxV = INT_MIN;
        
        for (int i = 0; i < n; ++i) {
            minV = min(minV, nums[i]);
            maxV = max(maxV, nums[i]);
        }
        
        //special case [1,1,1,2,1,1], [1,1,1,1,1,1]
        if (maxV - minV <= 1) return maxV - minV; 
        
        int bucketNum = min(n, maxV - minV);   //important!!!
        int bucketLen = (maxV - minV) / bucketNum;
        vector<bucketType> buckets(bucketNum);
        
        // the buckets are [ ) range
        for (int i = 0; i < n; ++i) {
            int index = (nums[i] - minV) / bucketLen;
            if (index >= bucketNum) index = bucketNum - 1;
  
            buckets[index].count++;
            buckets[index].maxNum = max(buckets[index].maxNum, nums[i]);
            buckets[index].minNum = min(buckets[index].minNum, nums[i]);
        }

        int maxDist = 0;
        int lastElem = buckets[0].maxNum;
        for (int i = 1; i < bucketNum; ++i) {
            if (buckets[i].count == 0) continue;
            maxDist = max(maxDist, buckets[i].minNum - lastElem);
            lastElem = buckets[i].maxNum;
        }
        return maxDist;
    }
};
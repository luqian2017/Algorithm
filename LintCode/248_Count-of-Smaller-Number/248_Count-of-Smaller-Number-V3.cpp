class Solution {
public:
    /**
     * @param A: An integer array
     * @param queries: The query list
     * @return: The number of element in the array that are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        int n = A.size();
        if (n == 0) return vector<int>(queries.size());
        map<int, int> num2Freq; //num, freq
        
        for (int i = 0; i < n; ++i) {
            num2Freq[A[i]]++;
        }

        vector<int> nums(num2Freq.size());
        int index = 0;
        for (auto a : num2Freq) {
            nums[index++] = a.first;
        }

        vector<int> preSums(nums.size());   //preSum[i] is the preSum of index2Num[i];
        preSums[0] = num2Freq[nums[0]];
        
        for (int i = 1; i < nums.size(); ++i) {
            preSums[i] = preSums[i - 1] + num2Freq[nums[i]];
        }

        vector<int> result;
        for (int i = 0; i < queries.size(); ++i) {
            int queryNum = queries[i];
            
            //find the closest index in nums[] that is smaller than queryNum
            int findIndex = -1;
            int start = 0, end = nums.size() - 1;
            while(start + 1 < end) {
                int mid = start + (end -start) / 2;
                if (nums[mid] < queryNum) {
                    start = mid;
                } else if (nums[mid] > queryNum) {
                    end = mid;
                } else {
                    //findIndex = mid;
                    end = mid;
                }
            }

            if (nums[start] == queryNum) findIndex = start - 1;
            if (nums[end] == queryNum) findIndex = end - 1;

            if (nums[end] < queryNum) findIndex = end;
            else if (nums[start] < queryNum) findIndex = start;

            if (findIndex == -1) 
                result.push_back(0);
            else 
                result.push_back(preSums[findIndex]);
        }
        
        return result;
    }
};
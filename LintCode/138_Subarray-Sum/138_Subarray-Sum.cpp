class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySum(vector<int> &nums) {
        vector<int> result;
        long long sum = 0;
        unordered_map<long long, int> hashmap;   //<sum, index>

        for (int i = 0; i < nums.size(); ++i) {

            sum += nums[i];

            if (sum == 0) return vector<int>{0, i}; 

            if (hashmap.find(sum) != hashmap.end()) {
                result.push_back(hashmap[sum] + 1);
                result.push_back(i);
                break;
            }
            hashmap[sum] = i; 
        }
        
        return result;        
    }
};
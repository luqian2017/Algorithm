Consider the following array:
[8, 1, 2, -3 , 4]

We maintain a sum[i] which stores the sum of the element from the beginning to current index i, and use a hashmap to store the <sum, index>. 
sum[0] = 8;
sum[1] = 9;
sum[2] = 11;
sum[3] = 8;
sum[4] = 12;

We can see sum[0] == sum[3]. It means the sum of index 1 to index 2 is 0. Thus we can return [1, 2].

The above algorithm also works for the case for [3, 2, 0, 1, 7], which will return [2, 2].

Sometimes the sum is 0 only in the end of the array, for example, input array = [1, -1], in such case we need to add a judgement 
        if (sum == 0) return vector<int>{0, i}; 

It also works for the special test case input array = [0].

//////////////

There is another version online, which uses hash[0] = -1 and result.push_back(hash[sum] + 1) thus avoid using the additional if condition:
    vector<int> subarraySum(vector<int> nums){
        unordered_map<int, int> hash;
        
        int sum = 0;
        hash[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (hash.find(sum) != hash.end()) {
                vector<int> result;
                result.push_back(hash[sum] + 1);
                result.push_back(i);
                return result;
            }
            hash[sum] = i;
        }
        
        vector<int> result;
        return result;
    }
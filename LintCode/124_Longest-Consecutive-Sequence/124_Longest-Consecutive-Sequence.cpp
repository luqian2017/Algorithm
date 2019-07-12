
class Solution {
public:
    /**
     * @param num: A list of integers
     * @return: An integer
     */
    int longestConsecutive(vector<int> &num) {
        int n = num.size();
        unordered_map<int, int> um; //number vs counter?
        for (int i = 0; i < n; ++i) {
            if (um.find(num[i]) == um.end()) {
                um[num[i]] = 1;
            } else {
                um[num[i]]++;
            }
        }
        int count = 0, maxCount = 0;
        
        for (int i = 0; i < n; ++i) {
            if (um[num[i]] > 0) {
                int number = num[i];
                count = 0;
                while(um[number] > 0) {
                    um.erase(number);
                    number++;
                    count++;
                }
                number = num[i] - 1;
                while(um[number] > 0) {
                    um.erase(number);
                    number--;
                    count++;
                }
                maxCount = max(count, maxCount);
            }
        }
        
        return maxCount;
    }
};
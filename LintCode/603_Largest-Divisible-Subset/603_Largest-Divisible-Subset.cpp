class Solution {
public:
    /*
     * @param nums: a set of distinct positive integers
     * @return: the largest subset 
     */
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        int len = nums.size();
        vector<int> A(len, 0);  //A[] stores the subset length of each A[i]
        map<int, vector<int>> mp;   //for nums[i], i and the subset
        sort(nums.begin(), nums.end());
        A[0] = 1;
        mp[0].push_back(nums[0]);
        int g_maxLen = 0;
        int g_maxId = 0;
        for (int i = 1; i < len; ++i) {
            int maxLen = 0;
            int maxId = 0;
            for (int j = 0; j < i; ++j) {
                
                if (!divisable(nums[i], mp[j])) continue;
                if (A[j] > maxLen) {
                    maxLen = A[j];
                    maxId = j;
                }
            }
            
            if (maxLen > 0) {
                A[i] = maxLen + 1;
                mp[i] = mp[maxId];
                mp[i].push_back(nums[i]);
            } else {
                A[i] = 1;
                mp[i] = vector<int>(1, nums[i]);
                
            }
            
            if (A[i] > g_maxLen) {
                g_maxLen = A[i];
                g_maxId = i;
            }
        }
        return mp[g_maxId];
    }
    
private:
    bool divisable(int n, vector<int> &nums) {
        for (auto num : nums) {
          //  if ((num % n != 0) && (n % num != 0)) return false;
          if (n % num != 0) return false;

        }
        
        return true;
    }
    
};
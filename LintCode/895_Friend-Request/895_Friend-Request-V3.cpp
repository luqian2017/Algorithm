class Solution {
public:
    /**
     * @param ages: The ages
     * @return: The answer
     */
    int friendRequest(vector<int> &ages) {
        int n = ages.size();
        vector<int> distribution(151, 0);
        for (int i = 0; i < n; ++i) {
            distribution[ages[i]]++;
        }
        
        vector<int> presums(151, 0);
        for (int i = 1; i < 151; ++i) {
            presums[i] = presums[i - 1] + distribution[i];
        }
        
        int reqCount = 0;
        for (int i = 1; i <= 100; ++i) {
            if (distribution[i] == 0) continue;
            int lowLimit = i / 2 + 7;
            if (i > lowLimit) {
                reqCount += distribution[i] * (distribution[i] - 1);
                reqCount += (presums[i - 1] - presums[lowLimit]) * distribution[i];    
            }
        }

        for (int i = 101; i <= 150; ++i) {
            if (distribution[i] == 0) continue;
            reqCount += distribution[i] * (distribution[i] - 1);
            reqCount += (presums[i - 1] - presums[99]) * distribution[i];
        }
        
        return reqCount;
    }
};
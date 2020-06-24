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
        
        int reqCount = 0;
        for (int i = 1; i <= 100; ++i) {
            if (distribution[i] == 0) continue;
            int lowLimit = i / 2 + 7;
            if (i > lowLimit) reqCount += distribution[i] * (distribution[i] - 1);
            int addCount = 0;
            for (int j = lowLimit + 1; j < i; ++j) {
                if (distribution[j] == 0) continue;
                addCount += distribution[j];
            }
            reqCount += addCount * distribution[i];
        }

        for (int i = 101; i <= 150; ++i) {
            if (distribution[i] == 0) continue;
            reqCount += distribution[i] * (distribution[i] - 1);
            int addCount = 0;
            for (int j = 100; j < i; ++j) {
                if (distribution[j] == 0) continue;
                addCount += distribution[j];
            }
            reqCount += addCount * distribution[i];
        }
        
        return reqCount;
    }
};
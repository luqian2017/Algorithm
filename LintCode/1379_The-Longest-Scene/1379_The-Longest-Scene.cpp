class Solution {
public:
    /**
     * @param str: The scene string
     * @return: Return the length longest scene
     */
    int getLongestScene(string &str) {
        int strLen = str.size();
        if (strLen == 0) return 0;
        int result;
        vector<vector<int>> vecs(26, vector<int>());
        
        //pre-processing
        for (int i = 0; i < strLen; ++i) {
            int letterIndex = str[i] - 'a';
            vecs[letterIndex].push_back(i);
        }
        
        //pair<int, int> wholeIntervals[26];
        vector<pair<int, int>> wholeIntervals(26);
        
        for (int i = 0; i < 26; ++i) {
            if (vecs[i].size() > 0) {
                wholeIntervals[i].first = vecs[i][0];
                wholeIntervals[i].second = vecs[i][vecs[i].size() - 1];
            }
        }
        
        sort(wholeIntervals.begin(), wholeIntervals.end());
        
        int currIntervalSize = wholeIntervals[0].second - wholeIntervals[0].first;
        int currIntervalBegPos = wholeIntervals[0].first;
        int currIntervalEndPos = wholeIntervals[0].second;
        
        int maxIntervalSize = wholeIntervals[0].second - wholeIntervals[0].first;
        
        for (int i = 1; i < 26; ++i) {

            if (wholeIntervals[i].first <= currIntervalEndPos) {
                currIntervalSize = wholeIntervals[i].second - currIntervalBegPos;
                currIntervalEndPos = wholeIntervals[i].second; 
            } else {
                currIntervalSize = wholeIntervals[i].second - wholeIntervals[i].first;
                currIntervalBegPos = wholeIntervals[i].first;
                currIntervalEndPos = wholeIntervals[i].second;
            }
            
            maxIntervalSize = max(maxIntervalSize, currIntervalSize);
        }

        return maxIntervalSize + 1;
    }
};
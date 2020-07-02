class Solution {
public:
    /**
     * @param frames: A series of frames
     * @return: Find the longest feature movement
     */
    int FeatureExtraction(vector<vector<int>> &frames) {
        int len = frames.size();
        int max_count = 0;
        
        map<pair<int, int>, int> preFreq; //<coordinate, count>
        map<pair<int, int>, int> curFreq; //<coordinate, count>
        
        for (int i = 0; i < len; ++i) {
            int feat_count = frames[i][0];
            for (int j = 0; j < feat_count; ++j) {
                
                pair<int, int> coordinate = {frames[i][2 * j + 1], frames[i][2 * j + 2]};
                if (preFreq.find(coordinate) != preFreq.end()) {
                    curFreq[coordinate] = preFreq[coordinate] + 1;
                } else {
                    curFreq[coordinate] = 1;
                }
                
                max_count = max(max_count, curFreq[coordinate]);
            }

            preFreq = curFreq;
            curFreq.clear();
        }
        
        return max_count;
    }
};
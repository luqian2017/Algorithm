class Solution {
public:
    /**
     * @param target: The target distance
     * @param original: The original gas
     * @param distance: The distance array
     * @param apply: The apply array
     * @return: Return the minimum times
     */
    int getTimes(int target, int original, vector<int> &distance, vector<int> &apply) {
        int n = distance.size();
        if (n == 0) return 0;
        vector<int> stations; // the necessary stations
        for (int i = 0; i < n; ++i) {
            if (distance[i] >= target) {
                stations.push_back(target);
                break;
            } else {
                stations.push_back(distance[i]);
            }
        }
        
        if (target > distance[distance.size() - 1]) {
            stations.push_back(target);
        }

        //Each time select the station that has the most gas (maxHeap),
        //so the # of refule is the minimum.
        priority_queue<int> maxHeap;  
        int currGas = original;
        int currPlace = 0;
        int refuelCount = 0;
        for (int i = 0; i < stations.size(); ++i) {

            while (currGas < stations[i] - currPlace && !maxHeap.empty()) {
                currGas += maxHeap.top();
                maxHeap.pop();
                refuelCount++;
            }
            
            if (currGas < stations[i] - currPlace) return -1;
                           
            currGas -= stations[i] - currPlace;
            if (i != stations.size() - 1) { // the last station is target
                maxHeap.push(apply[i]);
            }
            currPlace = stations[i];
        }
        
        return refuelCount;
    }
};
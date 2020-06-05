class Solution {
public:
    /**
     * @param houses: positions of houses
     * @param heaters: positions of heaters
     * @return: the minimum radius standard of heaters
     */
    int findRadius(vector<int> &houses, vector<int> &heaters) {
       int num_house = houses.size();
       int num_heater = heaters.size();
       int radius = 0;
       sort(heaters.begin(), heaters.end());
       int minDist = 0;
   
       for (int i = 0; i < num_house; ++i) {
           int start = 0, end = num_heater - 1;
           int dist = INT_MAX;
           while(start + 1 < end) {
               int mid = start + (end - start) / 2;
               if (heaters[mid] == houses[i]) {
                   dist = 0;
                   break;
               } else if (heaters[mid] < houses[i]) {
                   start = mid;
               } else {
                   end = mid;
               }
           }
           
           if (dist > 0) {
               dist = min(abs(houses[i] - heaters[start]), abs(houses[i] - heaters[end]));
               minDist = max(minDist, dist);
           }
       }
       return minDist;
    }
};
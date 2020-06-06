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
       int start = 0, end = max(abs(heaters[num_heater - 1] - houses[0]), abs(heaters[0] - houses[num_house - 1]));

       while(start + 1 < end) {
           int mid = start + (end - start) / 2;
           if (satisfied(houses, heaters, mid)) {
               end = mid;
           } else {
               start = mid;
           }
       }
       
       if (satisfied(houses, heaters, start)) return start;
       return end;
    }

private:
    bool satisfied(vector<int> &houses, vector<int> &heaters, int target) {
       
       int num_house = houses.size();
       int num_heater = heaters.size();
       for (int i = 0; i < num_house; ++i) {
           int closestDist = INT_MAX;

           //find the closest heaters
           int start = 0, end = num_heater - 1;
           while(start + 1 < end) {
               int mid = start + (end - start) / 2;
               if (heaters[mid] == houses[i]) {
                   closestDist = 0;
                   break;
               } else if (heaters[mid] < houses[i]) {
                   start = mid;
               } else {
                   end = mid;
               }
           }
           
           if (closestDist > 0) {
               closestDist = min(abs(houses[i] - heaters[start]), abs(houses[i] - heaters[end]));
               if (closestDist > target) {
                   return false;
               }
           }
       }
       return true;
    }
};c
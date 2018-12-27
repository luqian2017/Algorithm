/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
    /**
     * @param coordinates: The radars' coordinate
     * @param radius: Detection radius of radars
     * @return: The car was detected or not
     */
    string radarDetection(vector<Point> &coordinates, vector<int> &radius) {
        int lenC = coordinates.size();
        int lenR = radius.size();
        if (lenC == 0) return "NO";
        
        int minY = INT_MAX, maxY = INT_MIN;
        int upperbound, lowerbound;
        
        for (int i = 0; i < lenC; ++i) {
            upperbound = coordinates[i].y + radius[i];
            lowerbound = coordinates[i].y - radius[i];
            
            if (upperbound > maxY) maxY = upperbound;
            if (lowerbound < minY) minY = lowerbound;
        }
        
        if ((minY > 0) || (maxY < 1)) return "NO";
        
        return "YES";
    }
};
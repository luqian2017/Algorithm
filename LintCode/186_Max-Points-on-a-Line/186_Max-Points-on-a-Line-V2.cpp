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
     * @param points: an array of point
     * @return: An integer
     */
    int maxPoints(vector<Point> &points) {
        int n = points.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            int duplicates = 1, max_slope_dup = 0;
            int dx = 0, dy = 0, gcd_xy = 0;
            map<pair<int, int>, int> um;
            for (int j = i + 1; j < n; j++) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    duplicates++;
                    continue;
                }
                dy = points[j].y - points[i].y;
                dx = points[j].x - points[i].x;
                gcd_xy = gcd(dx, dy);
                um[{dy / gcd_xy, dx / gcd_xy}]++;
                max_slope_dup = max(max_slope_dup, um[{dy / gcd_xy, dx / gcd_xy}]);
            }
            res = max(res, duplicates + max_slope_dup);
        }
        return res;
    }
private:
    int gcd(const int a, const int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
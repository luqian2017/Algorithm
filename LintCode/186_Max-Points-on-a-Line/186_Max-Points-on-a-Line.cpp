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
        if (n == 0) return 0;
        int max_num = 1;
        for (int i = 0; i < n; ++i) {
            //unordered_map<pair<int, int>, int> um;  //point, # of on line
            map<pair<int, int>, int> um;  //point, # of on line
            int num_dup = 1;
            for (int j = i + 1; j < n; ++j) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    num_dup++;
                    continue;
                }
                int dx = points[i].x - points[j].x;
                int dy = points[i].y - points[j].y;
                int gcd_v = gcd(dx, dy);
                um[{dx / gcd_v, dy / gcd_v}]++;
            } 
            max_num = max(max_num, num_dup);
            for (auto m : um) {
                max_num = max(max_num, m.second + num_dup);
            }
        }
        return max_num;
    }
private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
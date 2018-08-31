/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * }; * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

bool operator < (const Point &a, const Point &b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}


long long distance(const Point &a, const Point &b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

class Solution {
public:
    /**
     * @param points: a list of points
     * @param origin: a point
     * @param k: An integer
     * @return: the k closest points
     */
    vector<Point> kClosest(vector<Point> &points, Point &origin, int k) {
        vector<Point> result;
        for (auto p : points) {
            long long dist = distance(p, origin);
            mp[dist].insert(p);
        }
        
        int count = 0;
        for (auto m : mp) {
           // sort(m.second.begin(), m.second.end());
            for (auto n : m.second) {
                if (count == k) break;
                result.push_back(n);
                count++;
            }
            
        }
        
       
        return result;
    }

private:
    map<long long, multiset<Point>> mp;
};
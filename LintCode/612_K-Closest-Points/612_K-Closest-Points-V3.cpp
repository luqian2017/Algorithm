/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
 
Point originPoint;
int distance (const Point & a, const Point & b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
} 

bool operator < (const Point & a, const Point & b) {
    int dist1 = distance(a, originPoint);
    int dist2 = distance(b, originPoint);
    if (dist1 == dist2) {
        if (a.x == b.x) return a.y < b.y;
        else return a.x < b.x;
    } else {
        return dist1 < dist2;
    }
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
        int n = points.size();
        originPoint = origin;
        sort(points.begin(), points.end());
        
        priority_queue<Point> pq;
        for (int i = 0; i < n; ++i) {
            pq.push(points[i]);
            if (i >= k) {
                if (points[i] < pq.top()) pq.push(points[i]);
                pq.pop();
            }
        }
        vector<Point> results;
        while(!pq.empty()) {
            results.push_back(pq.top());
            pq.pop();
        }
        sort(results.begin(), results.end());
        return results;
    }
};
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

long long distance(const Point &a, const Point &b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

Point g_origin;

class compare {
public:

  bool operator() (const Point &a, const Point &b) const {
      long long dist_a = distance(a, g_origin);
      long long dist_b = distance(b, g_origin);
      if (dist_a == dist_b) {
          if (a.x == b.x) return a.y < b.y;
          return a.x < b.x;
      } 
      return dist_a < dist_b;
  }

  
};

class Solution {
public:
    /**
     * @param points: a list of points
     * @param origin: a point
     * @param k: An integer
     * @return: the k closest points
     */
    vector<Point> kClosest(vector<Point> &points, Point &origin, int k) {
        g_origin = Point(origin);       
        priority_queue<Point, vector<Point>, compare> pq;  //最大堆
        int count = points.size();
        for (int i = 0; i < count; ++i) {
            pq.push(points[i]);
            if (pq.size() > k) pq.pop();
        }
        
        vector<Point> result;
        while(!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
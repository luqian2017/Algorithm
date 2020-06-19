struct Circle {
    pair<double, double> center;
    double radius;
    Circle(const pair<double, double> & p, const double r) : center(p), radius(r) {}
};

class Solution {
public:
    /**
     * @param position: the position of circle A,B and point P.
     * @return: if two circle intersect return 1, otherwise -1.
     */
    int IfIntersect(vector<double> &position) {
        Circle A({position[0], position[1]}, position[2]);
        Circle B({position[3], position[4]}, position[5]);
        Circle P({position[6], position[7]}, 0);
        
        pair<double, double> M = {B.center.first - (P.center.second - A.center.second), B.center.second + (P.center.first - A.center.first)};
        
        double dist_min, dist_max;
        if (cross_prod(A.center, B.center, M) * cross_prod(B.center, P.center, M) > 0) {
            dist_min = dis_p2l(B.center, A.center, P.center);
        } else {
            dist_min = min(dist_p2p(A.center, B.center), dist_p2p(P.center, B.center));
        }
        
        dist_max = min(dist_p2p(A.center, B.center), dist_p2p(P.center, B.center));
        
        if (dist_min > A.radius + B.radius || dist_max < abs(A.radius - B.radius)) return -1;
        return 1;
    }

private:
    //Cross product p3p1 X p3p2
    double cross_prod(pair<double, double> & p1, pair<double, double> & p2, pair<double, double> & p3) {
        return (p1.first - p3.first) * (p2.second - p3.second) - (p2.first - p3.first) * (p1.second - p3.second);
    }
    
    //distance between p1 and p2
    double dist_p2p(pair<double, double> & p1, pair<double, double> & p2) {
        return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
    }
    
    //distance from p1 to line p2p3
    double dis_p2l(pair<double, double> & p1, pair<double, double> & p2, pair<double, double> & p3) {
        return abs(cross_prod(p1, p2, p3) / dist_p2p(p2, p3));
    }
};
class Solution {
public:
    /**
     * @param p: the point List
     * @return: the numbers of pairs which meet the requirements
     */
    int pairNumbers(vector<Point> &p) {
        int n = p.size();
        int oddXoddY = 0, oddXevenY = 0, evenXoddY = 0, evenXevenY = 0;

        for (int i = 0; i < n; ++i) {
            if (p[i].x & 0x1) {
                if (p[i].y & 0x1) {
                    oddXoddY++;
                } else {
                    oddXevenY++;
                }
            } else {
                if (p[i].y & 0x1) {
                    evenXoddY++;
                } else {
                    evenXevenY++;
                }
            }
        }

        int result = 0;
        
        result = oddXoddY * (oddXoddY - 1) / 2 +
                 evenXevenY * (evenXevenY - 1) / 2 +
                 oddXevenY * (oddXevenY - 1) / 2 +
                 evenXoddY * (evenXoddY - 1) / 2;

        return result;
    }
};
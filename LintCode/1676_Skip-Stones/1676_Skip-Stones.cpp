class Solution {
public:
    /**
     * @param n: The total number of stones.
     * @param m: The total number of stones you can remove.
     * @param target: The distance from the end to the starting point.
     * @param d: The array that the distance from the i rock to the starting point is d[i].
     * @return: Return the maximum value of the shortest jump distance.
     */
    int getDistance(int n, int m, int target, vector<int> &d) {
        if (n == 0) return target;
        int start = 0, end = target;
        d[n] = target;
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (isValid(n, m, target, d, mid)) start = mid;
            else end = mid;
        }
        if (isValid(n, m , target, d, end)) return end;
        return start;
    }
    
private:
    bool isValid(int n, int m, int target, vector<int> & d, int gap) {
        int count = 0, lastPos = 0;  
        for (int i = 0; i <= n; ++i) {
            if (d[i] - lastPos < gap) count++;
            else lastPos = d[i];
        }
        
        if (count <= m) return true;
        return false;
    }
};
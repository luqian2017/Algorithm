class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        int n = S.size();
        if (n < 3) return 0;
        
        int p1 = 0, p2 = 1, p3 = 2;
        int count  = 0;
        
        sort(S.begin(), S.end());
        while(p3 < n) {
            p1 = 0;
            while(p1 < p3 - 1) {
                p2 = p3 - 1;
                while(p1 < p2) {
                    if ((S[p1] + S[p2]) > S[p3]) {
                        p2--;
                        count++;
                    } else {
                        break;
                    }
                }
                p1++;
            }
            p3++;
        }

        return count;
    }
};
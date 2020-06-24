class Solution {
public:
    /**
     * @param ages: The ages
     * @return: The answer
     */
    int friendRequest(vector<int> &ages) {
        int ans = 0;
        for(int i = 0; i < ages.size(); i++) {
            for(int j = 0; j < ages.size(); j++) {
                if(i == j) {
                    continue;
                }
                int A = ages[i];
                int B = ages[j];
                if(B <= A && B > A / 2 + 7 && !(B < 100 && A > 100)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
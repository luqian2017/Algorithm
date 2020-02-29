class Solution {
public:
    /**
     * @param ages: 
     * @return: nothing
     */
    int numFriendRequests(vector<int> &ages) {
        int n = ages.size();
        sort(ages.begin(), ages.end());
        int numFriends = 0;
        
        for (int i = n - 1; i > 0; i--) {
            int A = ages[i];
            for (int j = i - 1; j >= 0; j--) {
                int B = ages[j];
                if (B <= A / 2 + 7) break;
                numFriends++;
                if (A == B) numFriends++;
            }
        }
        
        return numFriends;
        
    }
};
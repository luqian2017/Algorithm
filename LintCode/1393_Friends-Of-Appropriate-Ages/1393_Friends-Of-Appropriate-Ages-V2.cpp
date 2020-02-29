class Solution {
public:
    /**
     * @param ages: 
     * @return: nothing
     */
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int,int> mp;   //age, freq
        for (int &age: ages) mp[age]++;
        int res = 0;
        for (auto & a: mp) 
           for (auto & b: mp)
            if (request(a.first, b.first)) res += a.second * (b.second - (a.first == b.first ? 1 : 0));
        return res;
    }

    bool request(int a, int b) {
        //return !(b <= 0.5 * a + 7 || b > a || (b > 100 && a < 100));
        return !(b <= 0.5 * a + 7 || b > a);
    }
};
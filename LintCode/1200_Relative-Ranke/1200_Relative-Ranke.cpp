bool cmp(const pair<int, char> a, const pair<int, char> b) {
    return a.first > b.first;
}

class Solution {
public:
    /**
     * @param nums: List[int]
     * @return: return List[str]
     */
    vector<string> findRelativeRanks(vector<int> &nums) {
        int n = nums.size();
        vector<pair<int, int>> records(n); //<value, id>
        for (int i = 0; i < n; ++i) {
            records[i].first = nums[i];
            records[i].second = i;
        }
        sort(records.begin(), records.end(), cmp);
        
        vector<string> result(n);
        for (int i = 0; i < n; ++i) {
            if (i == 0) result[records[i].second] = "Gold Medal";
            else if (i == 1) result[records[i].second] = "Silver Medal";
            else if (i == 2) result[records[i].second] = "Bronze Medal";
            else result[records[i].second] = to_string(i + 1);
        }

        return result;
    }
};
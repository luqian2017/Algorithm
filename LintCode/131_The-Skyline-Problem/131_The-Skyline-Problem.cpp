class Solution {
public:
    /**
     * @param buildings: A list of lists of integers
     * @return: Find the outline of those buildings
     */
    vector<vector<int>> buildingOutline(vector<vector<int>> &buildings) {
        vector<pair<int, int>> h, record;
        multiset<int> m;
        int pre = 0, cur = 0;

        for (auto &a : buildings) {
            h.push_back({a[0], -a[2]});
            h.push_back({a[1], a[2]});
        }
        sort(h.begin(), h.end());
        m.insert(0);
        int savedTime = 0;

        for (auto &a : h) {
            if (a.second < 0) m.insert(-a.second);
            else m.erase(m.find(a.second));
            cur = *m.rbegin();
            if (cur != pre) {
                record.push_back({a.first, cur});
                pre = cur;
            }
        }

        vector<vector<int>> res;
        int n = record.size();

        for (int i = 1; i < n; ++i) {
            if (record[i - 1].second > 0)
                res.push_back({record[i - 1].first, record[i].first, record[i - 1].second});
        }
        return res;
    }
};
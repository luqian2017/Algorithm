class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());  //按照区间左值排序
        vector<vector<int>> ans;
        
        int i = 0;
        while (i < n) {
            int L = intervals[i][0], R = intervals[i][1];
            do {
                R = max(R, intervals[i][1]);
                i++;
            } while (i < n && R >= intervals[i][0]);
            ans.push_back({L, R});
        }
        return ans;        
    }
};
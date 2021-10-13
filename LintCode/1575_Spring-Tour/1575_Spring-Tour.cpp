class Solution {
public:
    /**
     * @param a: The array a
     * @return: Return the minimum number of car
     */
    int getAnswer(vector<int> &a) {
        int n = a.size();
        if (n == 0) return 0;
        //sort(a.begin(), a.end());
        int total_cnt = 0;
        //int cnt_1 = 0, cnt_2 = 0, cnt_3 = 0, cnt_4 = 0;
        vector<int> cnt(5, 0);
        for (int i = 0; i < n; ++i) {
            cnt[a[i]]++;
        }
        total_cnt = cnt[4] + cnt[2] / 2;
        cnt[2] = (cnt[2] & 0x1) == 1;
        int min_cnt1_cnt3 = min(cnt[1], cnt[3]);
        total_cnt += min_cnt1_cnt3;
        if (cnt[1] == cnt[3]) {
            return total_cnt + cnt[2];
        } else if (cnt[1] > cnt[3]) {
            cnt[1] -= min_cnt1_cnt3;
            cnt[3] = 0;
        } else {
            cnt[3] -= min_cnt1_cnt3;
            cnt[1] = 0;
        }
        //now, we have some 1,1,1,...1,(2) or 3,3,3,...,3,(2) left
        if (cnt[1] > 0) { //we have some 1,1,1,...1,2
            total_cnt += cnt[1] / 4;
            cnt[1] %= 4;
            if (cnt[1] == 0) total_cnt += cnt[2];
            else if (cnt[1] == 3) total_cnt += 1 + cnt[2];
            else total_cnt += 1; //1 or 2, 1 can be combined with 2
        } else { //cnt[3] > 0
            total_cnt += cnt[3] + cnt[2];
        }
        return total_cnt;
    }
};
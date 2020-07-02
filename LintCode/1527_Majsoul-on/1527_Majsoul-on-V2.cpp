class Solution {
public:
    /**
     * @param cards: A list of cards.
     * @return: A list of feasible solution.
     */
    // 判断此时的14张牌是否可以和牌
    bool check(int *times)
    {
        int tmp[10];
        // i作为雀头
        for (int i = 1; i < 10; i++) {
            if (times[i] < 2) {
                continue;
            }
            // ok标记是否可以和牌的状态
            bool ok = true;
            for (int k = 1; k < 10; k++) {
                tmp[k] = times[k];
            }
            tmp[i] -= 2;
            for (int j = 1; j < 10 && ok; j++) {
                // 刻子jjj
                if (tmp[j] >= 3) {
                    tmp[j] -= 3;
                }
                while (tmp[j] && ok) {
                    if (j + 2 > 9) {
                        ok = false;
                        break;
                    }
                    // 顺子(j, j + 1, j + 2)
                    if (tmp[j + 1] && tmp[j + 2]) {
                        tmp[j]--;
                        tmp[j + 1]--;
                        tmp[j + 2]--;
                    }
                    else {
                        ok = false;
                    }
                }
            }
            if (ok) {
                return true;
            }
        }
        return false;
    }
    
    vector<int> getTheNumber(vector<int> &cards) {
        // times[i]表示数字i出现的次数
        int times[10] = {0};
        vector <int> ans;
    	for (int i = 0; i < 13; i++) {
            times[cards[i]]++;
    	}
    	// 和牌：雀头+4*顺子/刻子
    	for (int i = 1; i < 10; i++) {
            if (times[i] < 4) {
                times[i]++;
                if (check(times)) {
                    ans.push_back(i);
                }
                times[i]--;
            }
    	}
    	if (ans.empty()) {
            ans.push_back(0);
    	}
	    return ans;
    }
};
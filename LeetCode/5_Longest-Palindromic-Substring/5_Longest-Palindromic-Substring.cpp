class Solution {
public:
    string getNewString(string s) {
        string newS = "#";
        for (int i = 0; i < s.size(); i++) {
            newS += s[i];
            newS += '#';
        }
        return newS;
    }
    
    string longestPalindrome(string s) {
        string newS = getNewString(s);
        int *r = new int[newS.size()], c;
        r[0] = 1, c = 0;        
        for (int i = 0; i < newS.size(); i++) {
            if (i >= c + r[c]) {
                r[i] = 1;
            } else {
                //r[i] = min(r[i'], c + r[c] - i);
                r[i] = min(r[2 * c - i], c + r[c] - i);
            }
            //暴力枚举字符串最大长度
            while (i - r[i] >= 0 && i + r[i] < newS.size() && newS[i - r[i]] == newS[i + r[i]]) {
                r[i]++;
            }
            if (c + r[c] < i + r[i]) c = i;   //需要更新了
        }
        
        int ans = 0;
        string res = "";
        for (int i = 0; i < newS.size(); i++) {
            if (r[i] <= ans) continue;
            ans = r[i];
            res = "";
            for (int j = i - r[i] + 1; j <= i + r[i] - 1; j++) {
                if (newS[j] == '#') continue;
                res += newS[j];
            }
        }
        return res;
    }
};
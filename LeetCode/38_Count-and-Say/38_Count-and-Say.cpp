class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string s = countAndSay(n - 1);
        string res = "";
        char curr_char = s[0];
        int curr_freq = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (curr_char == s[i]) curr_freq++;
            else {
                res += to_string(curr_freq) + curr_char;
                curr_char s= s[i];
                curr_freq = 1;
            }
        }
        res += to_string(curr_freq) + curr_char;
        return res;
    }
};
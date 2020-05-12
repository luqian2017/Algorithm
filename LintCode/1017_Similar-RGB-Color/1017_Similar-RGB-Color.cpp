class Solution {
public:
    /**
     * @param color: the given color
     * @return: a 7 character color that is most similar to the given color
     */
    string similarRGB(string &color) {
        int n = color.size();
        int C1 = 0, C2 = 0, C3 = 0;
        string S1, S2, S3;
        S1 = color.substr(1, 2);
        S2 = color.substr(3, 2);
        S3 = color.substr(5, 2);
        return '#' + similar(S1) + similar(S2) + similar(S3);
    }
    
private:
    string similar(const string S) {
        int ten = S[0] >= 'a' ? S[0] - 'a' + 10 : S[0] - '0';
        int digit = S[1] >= 'a' ? S[1] - 'a' + 10 : S[1] - '0';

        int C = ten * 16 + digit;
        int minDist = INT_MAX;
        int res_value = 0;
        string res_str = "";
        for (int i = -1; i <= 1; ++i) {
            if (ten == 0 && i == -1) continue;
            int candidate = (ten + i) * 16 + ten + i;
                int dist = abs(candidate - C);
            if (dist < minDist) {
                minDist = dist;
                res_value = candidate;
                if (ten + i >= 10) {
                    res_str = string(2, 'a' + ten + i - 10);
                } else {
                    res_str = string(2, '0' + ten + i);
                }
            }
        }
        return res_str;
    }
};
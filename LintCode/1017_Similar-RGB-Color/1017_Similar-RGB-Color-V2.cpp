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
        int num = ten * 16 + digit;
    
        int new_digit = num / 17 + ((num % 17) > 8 ? 1 : 0);
        char new_digit_char = (new_digit >= 10) ? 'a' + new_digit - 10 : '0' + new_digit;
        
        return string(2, new_digit_char);
    }
};
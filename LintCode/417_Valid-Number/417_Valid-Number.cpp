class Solution {
public:
    /**
     * @param s: the string that represents a number
     * @return: whether the string is a valid number
     */
    bool isNumber(string &s) {
        int n = s.size();
        if (n == 0) return false;
        
        int l = 0, r = n - 1;
        while (l <= r && s[l] == ' ') l++; //or use isspace(s[l])
        while (l <= r && s[r] == ' ') r--; //or use isspace(s[r])
        
        if (l > r) return false;
        
        if (s[l] == '+' || s[l] == '-') l++;
        if (l > r) return false;
        
        int pos_dot = -1, pos_e = -1;
        
        for (int i = l; i <= r; ++i) {
            //char c = tolower(s[i]);
            char c = s[i];
            if (isdigit(c)) continue;
            
            if (c == '.') {
                if (pos_dot < 0) pos_dot = i;
                else return false;
            } else if (c == 'e' || c == 'E') {
                if (pos_e < 0) pos_e = i;
                else return false;
            } else {
                return false;
            }
        }
        
        if (pos_e == l || pos_e == r) return false;
        if (pos_dot == l) return pos_dot < r && isdigit(s[pos_dot + 1]);
        if (pos_dot == r) return pos_dot > l && isdigit(s[pos_dot - 1]);
        
        return true;
    }
};
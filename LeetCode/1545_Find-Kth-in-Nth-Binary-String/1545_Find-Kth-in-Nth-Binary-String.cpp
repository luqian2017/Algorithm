class Solution {
public:
    char findKthBit(int n, int k) {
        string res = getString(n);
        return res[k - 1];
    }
private:
    string getString(int n) {
        if (n == 1) return "0";
        string res;
        string lastString = getString(n - 1);
        res = lastString;
        reverse(lastString.begin(), lastString.end());
        for (int i = 0; i < lastString.size(); ++i) {
            lastString[i] = (lastString[i] == '0') ? '1' : '0';
        }
        return res + "1" + lastString;
    }
};
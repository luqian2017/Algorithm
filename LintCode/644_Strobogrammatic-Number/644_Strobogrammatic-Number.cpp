class Solution {
public:
    /**
     * @param num: a string
     * @return: true if a number is strobogrammatic or false
     */
    bool isStrobogrammatic(string &num) {
        int n = num.size();
        int start = 0, end = n - 1;
        while(start < end) {
            if (!isUpsideDown(num[start], num[end])) return false;
            start++;
            end--;
        }
        
        return isUpsideDown(num[start], num[end]);
    }

private:
    bool isUpsideDown(char a, char b) {
        if (a == '0' && b == '0') return true;
        if (a == '1' && b == '1') return true;
        if (a == '8' && b == '8') return true;
        if (a == '6' && b == '9') return true;
        if (a == '9' && b == '6') return true;
        return false;
    }
};
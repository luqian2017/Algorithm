class Solution {
public:
    /**
     * @param s: a string
     * @return: return a string
     */
    string reverseString(string &s) {
        int n = s.size();
        string res(s);
        int start = 0, end = n - 1;
        while (start < end) {
            swap(res[start], res[end]);
            start++;
            end--;
        }
        return res;
    }
};
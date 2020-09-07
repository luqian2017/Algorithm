class Solution {
public:
    /**
     * @param s: the string
     * @return: the number of substring
     */
    int countSubstrings(string &s) {
        int len = s.size();
        unordered_set<string> result;
        for (int index = 0; index < 2 * len - 1; ++index) {
            int left = index / 2;
            int right = left + index % 2;
            while(left >= 0 && right < len && s[left] == s[right]) {
                result.insert(s.substr(left, right - left + 1));
                left--;
                right++;
            }
        }
        for (auto a : result) {
            cout<<a<<endl;
        }
        
        return result.size();
    }
};
class Solution {
public:
    /**
     * @param s: a string which consists of lowercase or uppercase letters
     * @return: the length of the longest palindromes that can be built
     */
    int longestPalindrome(string &s) {
        int n = s.size();
        if (n == 0) return 0;
        unordered_map<char, int> mp; //char, freq
        for (int i = 0; i < n; ++i) {
            mp[s[i]]++;
        }
        int sumEvenFreq = 0, sumOddFreq = 0, oddNum = 0;
        for (auto m : mp) {
            if (m.second & 0x1) {
                sumOddFreq += m.second - 1;
                oddNum++;
            }
            else sumEvenFreq += m.second;
        }

        return sumEvenFreq + sumOddFreq + (oddNum == 0 ? 0 : 1);
    }
};
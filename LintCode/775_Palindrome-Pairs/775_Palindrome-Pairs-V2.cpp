class Solution {
public:
    /**
     * @param words: a list of unique words
     * @return: all pairs of distinct indices
     */
    vector<vector<int>> palindromePairs(vector<string> &words) {
        int n = words.size();
        if (n == 0) return {{}};
        vector<vector<int>> result;
        unordered_map<string, int> um;
        for (int i = 0; i < n; ++i) um[words[i]] = i;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= words[i].size(); ++j) {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j);
                if (isPalindrome(left)) {
                    string tmpRight = right;
                    reverse(tmpRight.begin(), tmpRight.end());
                    if (um.find(tmpRight) != um.end() && um[tmpRight] != i) {
                        result.push_back({um[tmpRight], i});
                    }
                }
                if (right.size() > 0 && isPalindrome(right)) {
                    string tmpLeft = left;
                    reverse(tmpLeft.begin(), tmpLeft.end());
                    if (um.find(tmpLeft) != um.end() && um[tmpLeft] != i) {
                        result.push_back({i, um[tmpLeft]});
                    }
                }
            }
        }

        return result;
    }

private:
    bool isPalindrome(string s) {
        int n = s.size();
        if (n < 2) return true;
        int p1 = 0, p2 = n - 1;
        while(p1 < p2) {
            if (s[p1] != s[p2]) return false;
            p1++;
            p2--;
        }
        return true;
    }
};
class Solution {
public:
    /**
     * @param str: The input string
     * @return: The answer
     */
    vector<string> dataSegmentation(string &str) {
        vector<string> result;
        int n = str.size();
        int pos = 0;
        while(pos < n) {
            if (str[pos] == ' ') {
                pos++;
                continue;
            }
            if (!isalpha(str[pos])) {
                result.push_back(string(1, str[pos]));
                pos++;
            } else {
                int startPos = pos;
                while(pos < n && isalpha(str[pos])) pos++;
                result.push_back(str.substr(startPos, pos - startPos));
            }
        }
        return result;
    }
};
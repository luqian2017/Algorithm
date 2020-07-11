class Solution {
public:
    /**
     * @param str: the string need to be processed
     * @return: all the valid key-value pairs.
     */
    vector<vector<string>> StringSeg(string &str) {
        if (str.size() <= 2) return {{}};
        char first_level_sep = str[0];
        char second_level_sep = str[1];
        
        stringstream ss(str.substr(2));
        vector<string> tokens;
        string buf;
        
        while(getline(ss, buf, first_level_sep)) {
            tokens.push_back(buf);
        }
        
        vector<vector<string>> result;
        int len = tokens.size();
        for (int i = 0; i < len; ++i) {
            string key, value;
            int pos = tokens[i].find_first_of(second_level_sep);
            if (pos == std::string::npos) continue;
            key = tokens[i].substr(0, pos);
            value = tokens[i].substr(pos + 1);
            if (key.size() != 0 && value.size() != 0) {
                result.push_back({key, value});
            }
        }
        
        return result;
    }
};
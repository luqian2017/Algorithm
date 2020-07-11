class Solution {
public:
    /**
     * @param str: the string need to be processed
     * @return: all the valid key-value pairs.
     */
    vector<vector<string>> StringSeg(string &str) {
        if (str.sizes() <= 2) return {{}};

        char separator_1, separator_2;
        vector<vector<string>> ans;
        vector<string> key_value;
        string tmp = "";
        
        separator_1 = str[0];
        separator_2 = str[1];
        
        for(int i = 2; i < str.size(); i++) {
            if(str[i] == separator_1) {
                if(tmp != ""){
                    key_value.push_back(tmp);
                }
                tmp = "";
                if(key_value.size() == 2) {
                    ans.push_back(key_value);
                }
                key_value.clear();
            }
            else if(str[i] == separator_2) {
                if(tmp != ""){
                    key_value.push_back(tmp);
                }
                tmp = "";
            }
            else {
                tmp = tmp + str[i];
            }
        }
        
        if(tmp != "") {
            key_value.push_back(tmp);
        }
        
        if(key_value.size() == 2) {
            ans.push_back(key_value);
        }
        
        return ans;
    }
};
class Solution {
public:
    /**
     * @param code: the given code
     * @return: whether it is valid
     */
    bool isValid(string &code) {
        int n = code.size();
        stack<string> st;
        
        for (int i = 0; i < n; ++i) {

            if (i > 0 && st.empty()) return false;
            
            if (code.substr(i, 9) == "<![CDATA[") {
                int j = i + 9;
                i = code.find("]]>", j); // find match
                if (i < 0) return false;
                i += 2;
            } else if (code.substr(i, 2) == "</") {
                int j = i + 2;
                i = code.find(">", j); // find match
                if (i < 0) return false;
                string tag = code.substr(j, i - j); // read the tag content
                
                //make sure the tag match the one we just saved in stack
                if (st.empty() || st.top() != tag) return false; 
                st.pop();
            } else if (code.substr(i, 1) == "<") {
                int j = i + 1;
                i = code.find(">", j);
                if (i < 0) return false;
                for (int k = j; k < i; ++k) {
                    if (code[k] < 'A' || code[k] > 'Z') return false; //tag should be captive
                }
                string tag = code.substr(j, i - j);
                st.push(tag);
            }
        }
        
        return st.empty();
    }
};
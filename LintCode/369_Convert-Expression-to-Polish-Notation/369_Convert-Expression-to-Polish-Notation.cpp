class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The Polish notation of this expression
     */
    vector<string> convertToPN(vector<string> &expression) {
        int n = expression.size();
        stack<string> st;
        map<string, int> mp; //operator, priority
        vector<string> result;
        string topStr;
        mp["+"] = 1;
        mp["-"] = 1;
        mp["*"] = 2;
        mp["/"] = 2;
        
        for (int i = n - 1; i >= 0; --i) {
            string str = expression[i];
            if (str.size() > 1 || isdigit(str[0])) 
                result.push_back(str);
            else if (str == ")") 
                st.push(str);
            else if (str == "(") {
                while(st.top() != ")") {
                    topStr = st.top();
                    st.pop();
                    result.push_back(topStr);
                }
                st.pop();
            } else { //+-*/
               
                while(!st.empty() && (!isOperator(str) || mp[st.top()] > mp[str])) {
                    topStr = st.top();
                    st.pop();
                    result.push_back(topStr);            
                }
                st.push(str);
            }
                
        }
        
        while(!st.empty()) {
            topStr = st.top();
            st.pop();
            result.push_back(topStr);
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
private:
    bool isOperator(string s) {
        return (s.size() == 1 && !isdigit(s[0]));
    }
};
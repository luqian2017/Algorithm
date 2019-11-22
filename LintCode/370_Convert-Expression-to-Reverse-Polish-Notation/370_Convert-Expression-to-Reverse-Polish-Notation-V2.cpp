class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The Reverse Polish notation of this expression
     */
     
    vector<string> convertToRPN(vector<string> &expression) {
        int n = expression.size();
        if (n == 0) return vector<string>();
        
        vector<string> result;
        stack<string> st;
        map<string, int> priorityMp; //operator, priority
        priorityMp["+"] = 1;
        priorityMp["-"] = 1;
        priorityMp["*"] = 2;
        priorityMp["/"] = 2;

        for (int i = 0; i < n; ++i) {
            
            string str = expression[i];

            // if it is a number
            if (!isOperator(str)) {
                //st.push(str);
                result.push_back(str);
            }
            else if (str == "(") st.push(str);
            else if (str == ")") {
                while(st.top() != "(") {
                    string topStr = st.top();
                    st.pop();
                    result.push_back(topStr);
                } 
                st.pop(); //pop the '('
            } 
            // the operator case +-*/
            else {
                while(!st.empty() && priorityMp[st.top()] >= priorityMp[str]) {
                    result.push_back(st.top());
                    st.pop();
                                
                }
                st.push(str);
            }
        }

        while(!st.empty()) {
            string topStr = st.top();
            st.pop();
            result.push_back(topStr);
        }
        
        return result;
    }

private:
    bool isOperator(string s) {
        return (s.size() == 1 && !isdigit(s[0]));
    }
};
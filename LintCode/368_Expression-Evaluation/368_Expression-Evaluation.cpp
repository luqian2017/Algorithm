class Solution {
public:

    /**
     * @param expression: a list of strings
     * @return: an integer
     */
    int evaluateExpression(vector<string> &expression) {
        int result = 0;
        vector<string> RPN = convertToRPN(expression);
        
        stack<string> stk;
        
        for (auto s : RPN) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int a = stoi(stk.top());
                stk.pop();
                int b = stoi(stk.top());
                stk.pop();
                
                if (s == "+") stk.push(to_string(a + b));
                if (s == "-") stk.push(to_string(b - a));
                if (s == "*") stk.push(to_string(a * b));
                if (s == "/") stk.push(to_string(b / a));
            } else {
                stk.push(s);
            }
        }
        
        if (stk.empty()) return 0;
        else {
            result = stoi(stk.top());
            stk.pop();
            return result;
        }
    }

private:
    int getLevel(string opt) {
        if (opt == "(")
            return 0;
        if (opt == "+" || opt == "-")
            return 1;
        if (opt == "*" || opt == "/")
            return 2;

        return 3;
    }

    bool isOperator(string c) {
        return (c == "+" || c == "-" || c == "*" || c == "/");
    }
    //create reverse polish notation string
    vector<string> convertToRPN(vector<string> &expression) {
        stack<string> st;
        vector<string> RPN;
        int len = expression.size();
        for (int i = 0; i < len; ++i) {
            string c = expression[i];
            if (c == "(")
                st.push(c);
            else if (c == ")") {
                while (st.top() != "(") {
                    RPN.push_back(st.top());
                    st.pop();
                }
                st.pop();
            } else {
                if (!isOperator(c))
                    st.push(c);
                else {
                    while (!st.empty() && getLevel(st.top()) >= getLevel(c)) {
                            RPN.push_back(st.top());
                            st.pop();
                    }
                    st.push(c);
                }
            }
        }

        while (! st.empty()) {
            RPN.push_back(st.top());
            st.pop();
        }

        return RPN;
    }
};
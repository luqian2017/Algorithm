class Solution {
public:
    /**
     * @param tokens: The Reverse Polish Notation
     * @return: the value
     */
    int evalRPN(vector<string> &tokens) {
        int n = tokens.size();
        if (n == 0) return 0;
        n--;
        return helper(tokens, n);
    }

private:
    bool isOperator(const string & token) {
        return token.size() == 1 && string("+-*/").find(token) != string::npos;
	}
    
    int helper(vector<string> & tokens, int &index) {
        string token = tokens[index];
        if (!isOperator(token)) return stoi(token);
        int num1 = helper(tokens, --index);
        int num2 = helper(tokens, --index);
        if (token == "+") return num2 + num1;
        if (token == "-") return num2 - num1;
        if (token == "*") return num2 * num1;
        return num2 / num1;
    }
};

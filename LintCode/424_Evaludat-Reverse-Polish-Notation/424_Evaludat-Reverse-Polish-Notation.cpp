class Solution {
public:
    /**
     * @param tokens: The Reverse Polish Notation
     * @return: the value
     */
    int evalRPN(vector<string> &tokens) {
        int n = tokens.size();
        if (n == 0) return 0;
        int result = 0;
        stack<int> s;
        int num1 = 0, num2 = 0;
        for (int i = 0; i < n; ++i) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                s.push(stoi(tokens[i]));
            } else {
                num1 = s.top(); s.pop();
                num2 = s.top(); s.pop();
                if (tokens[i] == "+") s.push(num2 + num1);
                else if (tokens[i] == "-") s.push(num2 - num1);
                else if (tokens[i] == "*") s.push(num2 * num1);
                else s.push(num2 / num1); //note num2 != 0
            }
        }
    
        result = s.top(); s.pop();
        return result;
    }
};
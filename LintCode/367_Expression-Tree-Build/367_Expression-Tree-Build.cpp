/**
 * Definition of ExpressionTreeNode:
 * class ExpressionTreeNode {
 * public:
 *     string symbol;
 *     ExpressionTreeNode *left, *right;
 *     ExpressionTreeNode(string symbol) {
 *         this->symbol = symbol;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The root of expression tree
     */
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
    
    ExpressionTreeNode* build(vector<string> &expression) {
        vector<string> RPN = convertToRPN(expression);
        int len = RPN.size();
        stack<ExpressionTreeNode *> nodeStack;
        for (int i = 0; i < len; ++i) {
            string s = RPN[i];
            ExpressionTreeNode *pNode = new ExpressionTreeNode(s);
                if (s == "+" || s == "-" || s == "*" || s == "/") {
                    ExpressionTreeNode *pRight = nodeStack.top();
                    nodeStack.pop();
                    ExpressionTreeNode *pLeft = nodeStack.top();
                    nodeStack.pop();

                    pNode->right = pRight;
                    pNode->left = pLeft;
                    nodeStack.push(pNode);
            } else
                nodeStack.push(pNode);
        }       
        if (nodeStack.empty())
            return NULL;
        else
            return nodeStack.top(); 
    }
};
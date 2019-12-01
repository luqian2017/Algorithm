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
class MyTreeNode {
public:
    int val;
    ExpressionTreeNode * eNode;
    MyTreeNode(int v = 0, string s = ""){
        val = v;
        eNode = new ExpressionTreeNode(s);
    }
};

class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The root of expression tree
     */
    ExpressionTreeNode* build(vector<string> & expression) {
        if (expression.size() == 0) {
            return NULL;
        }
        
        stack<MyTreeNode *> stk;
        int base = 0;
        int val = 0;

        for (int i = 0; i < expression.size(); i++) {
            if (expression[i] == "(") {
                base += 10;
                continue;
            }
            
            if (expression[i] == ")") {
                base -= 10;
                continue;
            }
            
            val = getWeight(base, expression[i]);
            
            MyTreeNode * node = new MyTreeNode(val, expression[i]);
            
            while (!stk.empty() && node->val <= stk.top()->val) {
                node->eNode->left = stk.top()->eNode;
                stk.pop();
            }
            
            if (!stk.empty()) {
                stk.top()->eNode->right = node->eNode;
            }
            
            stk.push(node);
        }
        
        if (stk.empty()) {
            return NULL;
        }
        
        MyTreeNode * rst = stk.top();
        stk.pop();
        
        while (!stk.empty()) {
            rst = stk.top();
            stk.pop();
        }
        return rst->eNode;
    }

private:
     //Calculate weight for characters
     int getWeight(int base, string s) {
        if (s == "+" || s == "-") {
            return base + 1;
        }
        
        if (s == "*" || s == "/") {
            return base + 2;
        }
        return INT_MAX;
    }
};
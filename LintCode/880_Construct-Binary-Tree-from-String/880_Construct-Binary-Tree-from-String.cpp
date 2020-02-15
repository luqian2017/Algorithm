/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param s: a string
     * @return: a root of this tree
     */
    TreeNode * str2tree(string &s) {
        int n = s.size();
        if (n == 0) return NULL;
        int pos = 1;
        while(pos < s.size() && isdigit(s[pos])) pos++;

        TreeNode * rootNode = new TreeNode(stoi(s.substr(0, pos)));
        if (pos == n) return rootNode;
        //recursivly process the subtrees
        int bracketCount = 1;
        int startPos = pos;pos++;
        while(pos < n) {
            bracketCount += s[pos] == '(';
            bracketCount -= s[pos] == ')';
            if (bracketCount == 0) {
                string leftStr = s.substr(startPos + 1, pos - startPos - 1);
//                cout<<"leftStr="<<leftStr<<endl;
                rootNode->left = str2tree(leftStr);
                if (pos < n - 1) {
                    string rightStr = s.substr(pos + 2, n - pos - 3);
//                    cout<<"rightStr="<<rightStr<<endl;
                    rootNode->right = str2tree(rightStr);
                }
                break;
            }
            pos++;
        }
        return rootNode;
    }
};
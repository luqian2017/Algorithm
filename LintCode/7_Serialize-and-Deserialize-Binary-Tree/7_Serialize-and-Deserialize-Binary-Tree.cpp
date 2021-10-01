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
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
 string serialize(TreeNode * root) {
        cout << "serialize" << endl;
        if (!root) return "";
        string res = "";
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *frontNode = q.front();
            if (frontNode == NULL) {
                res = res + '#' + ' ';
            } else {
                res = res + to_string(frontNode->val) + ' ';
                TreeNode *leftNode = frontNode->left;
                q.push(leftNode);
                TreeNode *rightNode = frontNode->right;
                q.push(rightNode);
            }
            q.pop();
        }
        cout << "res = " << res << endl;
        return res;
    }
    
    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode * deserialize(string &data) {
        cout << "deserialize " << endl;
        if (data.size() == 0) return NULL;
        queue<TreeNode *> q;
        stringstream ss(data);
        string val;
        ss >> val;
        TreeNode *rootNode = new TreeNode(stoi(val));
        q.push(rootNode);
        while (!q.empty()) {
            TreeNode *frontNode = q.front();
            q.pop();
            if (frontNode == NULL) {

            } else {
                if (!(ss >> val)) break;
                if (val == "#") {
                    frontNode->left = NULL;
                } else {
                    cout << "1 val = " << val << endl;
                    frontNode->left = new TreeNode(stoi(val));
                    q.push(frontNode->left);
                }
                
                if (!(ss >> val)) break;
                if (val == "#") {
                    frontNode->right = NULL;
                } else {
                    cout << "2 val = " << val << endl;
                    frontNode->right = new TreeNode(stoi(val));
                    q.push(frontNode->right);
                }
            }
        }
        return rootNode;
    }
};


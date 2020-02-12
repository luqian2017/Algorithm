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
    string serialize(TreeNode * root) {
        if (!root) return "";
        stringstream ss;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode * node = q.front();
            q.pop();
            if (node) {
                ss << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                ss << "# ";
            }
        }
     //   cout<<"ss.str()="<<ss.str()<<endl;
        return ss.str();
    }

    TreeNode * deserialize(string &data) {
        if (data.empty()) return NULL;
        stringstream ss;
        ss << data;   //stringstream ss(data) is also OK
        queue<TreeNode *> q;
        string val = "";
        ss >> val; // the first token
        TreeNode * resNode = new TreeNode(stoi(val));
        TreeNode * curNode;
        
        q.push(resNode);
        while(!q.empty()) {
            TreeNode * node = q.front();
            q.pop();
            if (!(ss >> val)) break;  //ss reads to the end!
            if (val != "#") {
                curNode = new TreeNode(stoi(val));
                q.push(curNode);
                node->left = curNode;
            }
            if (!(ss >> val)) break;  //ss reads to the end!
            if (val != "#") {
                curNode = new TreeNode(stoi(val));
                q.push(curNode);
                node->right = curNode;
            }
        }
        return resNode;
    }
};
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
        stringstream ss;
        serialize(root, ss);
//        cout<<"ss.str()="<<ss.str()<<endl;
        return ss.str();
    }

    TreeNode * deserialize(string &data) {
        stringstream ss(data);
        return deserialize(ss);
    }
    
private:
    void serialize(TreeNode * root, stringstream & ss) {
        if (!root) ss << "# ";
        else {
            ss << root->val << " ";
            serialize(root->left, ss);
            serialize(root->right, ss);
        }
    }
    
    TreeNode * deserialize(stringstream & ss) {
        string val = "";
        ss >> val;
        if (val == "#") return NULL;
  //      cout<<"val="<<val<<endl;
        TreeNode * node = new TreeNode(stoi(val));
        node->left = deserialize(ss);
        node->right = deserialize(ss);
        return node;
    }
};
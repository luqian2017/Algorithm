/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        stringstream ss;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (!node) ss << "# ";
            else {
                ss << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            }
        }
        
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return NULL;
        stringstream ss;
        ss << data;
        
        string val = "";
        ss >> val;
        TreeNode * root = new TreeNode(stoi(val));
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (ss.eof()) break;
            ss >> val;
            if (val != "#") {
                node->left = new TreeNode(stoi(val));
                q.push(node->left);
            }
            if (ss.eof()) break;
            ss >> val;
            if (val != "#") {
                node->right = new TreeNode(stoi(val));
                q.push(node->right);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
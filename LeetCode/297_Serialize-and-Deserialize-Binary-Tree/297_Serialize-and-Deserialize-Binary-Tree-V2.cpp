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
        stringstream ss;
        serialize(root, ss);
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserialize(ss);
    }
private:
    void serialize(TreeNode* root, stringstream& ss) {
        if (!root) ss << "# ";
        else {
            ss << root->val << " ";
            serialize(root->left, ss);
            serialize(root->right, ss);
        }
    }
    
    TreeNode* deserialize(stringstream& ss) {
        string val;
        ss >> val;
        if (val == "#") return NULL;
        TreeNode *node = new TreeNode(stoi(val));
        node->left = deserialize(ss);
        node->right = deserialize(ss);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
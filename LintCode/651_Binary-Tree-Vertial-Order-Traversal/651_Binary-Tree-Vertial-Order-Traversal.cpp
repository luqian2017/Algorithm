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


struct Node {
    TreeNode * pTreeNode;
    int index;
    Node (TreeNode *pNode = NULL, int id = 0) : pTreeNode(pNode), index(id) {}
    bool operator < (const Node & n) const {
        return index < n.index;
    }
};

class Solution {
public:
    /**
     * @param root: the root of tree
     * @return: the vertical order traversal
     */
    vector<vector<int>> verticalOrder(TreeNode * root) {
        if (!root) return {};
        vector<vector<int>> result;
        inLevelOrderTraversal(root);
        
        for (auto m : mp) {
            result.push_back(m.second);
        }  
        
        return result;
    }
private:
    map<int, vector<int>> mp; //index, values
    
    void inLevelOrderTraversal(TreeNode * root) {
        if (!root) return;
        queue<Node> q;
        q.push(Node(root, 0));
        
        while(!q.empty()) {
            Node node = q.front();
            q.pop();
            mp[node.index].push_back(node.pTreeNode->val);
            if (node.pTreeNode->left) q.push(Node(node.pTreeNode->left, node.index - 1));
            if (node.pTreeNode->right) q.push(Node(node.pTreeNode->right, node.index + 1));
        }
    }
};
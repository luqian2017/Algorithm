/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * }; * Definition of TreeNode:
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
     * @param root: binary tree
     * @return: N-ary tree
     */
    UndirectedGraphNode* decode(TreeNode * root) {
        if (!root) return NULL;
        UndirectedGraphNode * NaryTreeRoot = new UndirectedGraphNode(root->val);
        
        TreeNode * leftNode = root->left;
        while(leftNode) {
            UndirectedGraphNode * currNode = decode(leftNode); 
            NaryTreeRoot->neighbors.push_back(currNode);
            leftNode = leftNode->right;
        }
        
        return NaryTreeRoot;
    }

    /**
     * @param root: N-ary tree
     * @return: binary tree
     */
    TreeNode * encode(UndirectedGraphNode* root) {
        if (!root) return NULL;
        
        TreeNode * binaryTreeRoot = new TreeNode(root->label);
        
        if (root->neighbors.size() > 0) {
            binaryTreeRoot->left = encode(root->neighbors[0]);
        }
        
        TreeNode *leftNode = binaryTreeRoot->left;
        for (int i = 1; i < root->neighbors.size(); ++i) {
            leftNode->right = encode(root->neighbors[i]);
            leftNode = leftNode->right;
        }
        
        return binaryTreeRoot;
    }
};
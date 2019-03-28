/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param A: a list of integer
     * @return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int> &A) {
        int n = A.size();
        if (n == 0) return NULL;
        return helper(A, 0, n - 1);
    }
    
private:
    SegmentTreeNode * helper(vector<int> &A, int start, int end) {
        if (start > end) return NULL;
        if (start == end) return new SegmentTreeNode(start, end, A[start]);
        int mid = start + (end - start) / 2;
        SegmentTreeNode * node = new SegmentTreeNode(start, end, A[start]);
        node->left = helper(A, start, mid);
        node->right = helper(A, mid + 1, end);
        node->max = max(node->left->max, node->right->max);
        return node;
    }
};
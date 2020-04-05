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
        // write your code here    SegmentTreeNode * build(int start, int end) {
       return buildTree(A, 0, A.size() - 1);
    }

private:
   SegmentTreeNode * buildTree(vector<int> & A, int start, int end) {
        if (start > end) return NULL;
        SegmentTreeNode * pNode = new SegmentTreeNode(start, end, 0);
        if (start == end) {
            pNode->max = A[start];
            return pNode;
        }
        int mid = start + (end - start) / 2;
        pNode->left = buildTree(A, start, mid);
        pNode->right = buildTree(A, mid + 1, end);
        pNode->max = max(pNode->left->max, pNode->right->max);
        return pNode;
   }
};
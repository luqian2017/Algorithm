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
     * @param root: The root of segment tree.
     * @param start: start value.
     * @param end: end value.
     * @return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode * root, int start, int end) {
        if (start == root->start && end == root->end) {
            return root->max;
        }
        
        int mid = root->start + (root->end - root->start) / 2;
        int leftMax = INT_MIN, rightMax = INT_MIN;
        if (start <= mid) {
            leftMax = query(root->left, start, min(mid, end));   //note it is min
        }
        if (end >= mid + 1) {
            rightMax = query(root->right, max(mid + 1, start), end); //note it is max
        }
        return max(leftMax, rightMax);
    }
};


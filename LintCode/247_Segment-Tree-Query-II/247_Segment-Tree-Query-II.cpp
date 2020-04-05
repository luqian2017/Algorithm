/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, count;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int count) {
 *         this->start = start;
 *         this->end = end;
 *         this->count = count;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param root: The root of segment tree.
     * @param start: start value.
     * @param end: end value.
     * @return: The count number in the interval [start, end]
     */
    int query(SegmentTreeNode * root, int start, int end) {
        if (!root || start > end) return 0;
        if (start <= root->start && end >= root->end) {
            return root->count;
        }
        int mid = root->start + (root->end - root->start) / 2;
        int leftCount = 0, rightCount = 0;
        if (start <= mid) {
            leftCount = query(root->left, start, min(mid, end));
        }
        if (end >= mid + 1) {
            rightCount = query(root->right, max(start, mid + 1), end);
        }
        return leftCount + rightCount;
    }
};
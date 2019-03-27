/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end) {
 *         this->start = start, this->end = end;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param start: start value.
     * @param end: end value.
     * @return: The root of Segment Tree.
     */
    SegmentTreeNode * build(int start, int end) {
        return helper(start, end);
    }
    
private:
    SegmentTreeNode * helper(int start, int end) {
        if (start > end) return NULL;
        
        SegmentTreeNode * node = new SegmentTreeNode(start, end);
        if (start == end) return node;
        
        int mid = start + (end - start) / 2;
        
        node->left = helper(start, mid);
        node->right = helper(mid + 1, end);
        return node;
    }
};
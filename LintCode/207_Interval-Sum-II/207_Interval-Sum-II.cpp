struct SgmtTreeNode {
    int start;
    int end;
    int sum;
    SgmtTreeNode * left;
    SgmtTreeNode * right;
    SgmtTreeNode(int start = 0, int end = 0, int sum = 0) {
        this->start = start;
        this->end = end;
        this->sum = sum;
        left = right = NULL;
    }
};

class Solution {
public:
    /* you may need to use some attributes here */

    /*
    * @param A: An integer array
    */
    Solution(vector<int> A) {
        root = build(A, 0, A.size() - 1);
    }

    /*
     * @param start: An integer
     * @param end: An integer
     * @return: The sum from start to end
     */
    long long query(int start, int end) {
        return querySegmentTreeNode(root, start, end);
    }

    /*
     * @param index: An integer
     * @param value: An integer
     * @return: nothing
     */
    void modify(int index, int value) {
        modifySegmentTreeNode(root, index, value);
        return;
    }

private:
    SgmtTreeNode * root;
    SgmtTreeNode * build(vector<int> & A, int start, int end) {
        if (start > end) return NULL;
        SgmtTreeNode * root = new SgmtTreeNode(start, end, 0);
        if (start == end) {
            root->sum = A[start];
        } else {
            int mid = start + (end - start) / 2;
            root->left = build(A, start, mid);
            root->right = build(A, mid + 1, end);
            root->sum = root->left->sum + root->right->sum;
        }

        return root;
    }
    
    long long querySegmentTreeNode(SgmtTreeNode * root, int start, int end) {
        if (start > end) return 0;
        if (start == root->start && end == root->end) return root->sum;
        
        int mid = root->start + (root->end - root->start) / 2;
        long long leftSum = 0, rightSum = 0;
        
        if (start <= mid) {
            leftSum = querySegmentTreeNode(root->left, max(start, root->start), min(mid, end));
        }
        
        if (end > mid) {
            rightSum = querySegmentTreeNode(root->right, max(mid + 1, start), min(end, root->end));
        } 
        
        return leftSum + rightSum;
    }
    
    void modifySegmentTreeNode(SgmtTreeNode * root, int index, int value) {
        if (index == root->start && index == root->end) {
            root->sum = value;
            return;
        }
        
        int mid = root->start + (root->end - root->start) / 2;
        
        if (index <= mid && index >= root->start) {
            modifySegmentTreeNode(root->left, index, value);
        } else if (index > mid && index <= root->end) {
            modifySegmentTreeNode(root->right, index, value);
        }
        
        root->sum = root->left->sum + root->right->sum;
    }
    
};
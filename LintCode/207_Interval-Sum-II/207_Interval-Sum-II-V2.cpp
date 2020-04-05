class SegmentTree {
public:
    int start, end;
    long long sum;
    SegmentTree * left, * right;
    SegmentTree(int _start = 0, int _end = 0, long long _sum = 0) : start(_start), end(_end), sum(_sum), left(NULL), right(NULL) {}

    static SegmentTree * build (vector<int> & A, int start, int end) {
        if (start > end) return NULL;
        SegmentTree * root = new SegmentTree(start, end, A[start]);
        if (start == end) return root;
        int mid = start + (end - start) / 2;
        root->left = build(A, start, mid);
        root->right = build(A, mid + 1, end);
        root->sum = root->left->sum + root->right->sum;
        return root;
    }
    
    static long long query(SegmentTree * root, int start, int end) {
        if (start <= root->start && end >= root->end) return root->sum;
        int mid = root->start + (root->end - root->start) / 2;
        int leftSum = 0, rightSum = 0;
        if (start <= mid) {
            leftSum = query(root->left, start, min(end, mid));
        }
        if (mid + 1 <= end) {
            rightSum = query(root->right, max(mid + 1, start), end);
        }
        return leftSum + rightSum;
    }
    
    static void modify(SegmentTree * root, int index, int value) {
        if (index == root->start && index == root->end) {
            root->sum = value;
            return;
        }
        int mid = root->start + (root->end - root->start) / 2;
        if (index <= mid) {
            modify(root->left, index, value);
        } else {
            modify(root->right, index, value);
        }
        root->sum = root->left->sum + root->right->sum;
    }
};

class Solution {
public:
    /*
    * @param A: An integer array
    */
    Solution(vector<int> A) {
        root = SegmentTree::build(A, 0, A.size() - 1);
    }

    /*
     * @param start: An integer
     * @param end: An integer
     * @return: The sum from start to end
     */
    long long query(int start, int end) {
        return SegmentTree::query(root, start, end);
    }

    /*
     * @param index: An integer
     * @param value: An integer
     * @return: nothing
     */
    void modify(int index, int value) {
        SegmentTree::modify(root, index, value);
    }
    
private:
    SegmentTree * root;
};
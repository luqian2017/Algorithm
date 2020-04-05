/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class SegmentTree {
public:
    SegmentTree *left, *right;
    int start, end;
    long long sum;
    SegmentTree(int _start = 0, int _end = 0, long long _sum = 0) : left(NULL), right(NULL), start(_start), end(_end), sum(_sum) {
    }

    static SegmentTree * build(vector<int> & A, int start, int end) {
        if (start > end) return NULL;
        SegmentTree * node = new SegmentTree(start, end, A[start]);
        if (start == end) return node;
        int mid = start + (end - start) / 2;
        node->left = build(A, start, mid);
        node->right = build(A, mid + 1, end);
        node->sum = node->left->sum + node->right->sum;
        return node;
    }

    static long long query(SegmentTree * root, int start, int end) {
        if (start <= root->start && end >= root->end) {
            return root->sum;
        }
        int mid = root->start + (root->end - root->start) / 2;
        long long leftSum = 0, rightSum = 0;
        if (start <= mid) {
            leftSum = query(root->left, start, min(mid, end));
        }
        if (mid + 1 <= end) {
            rightSum = query(root->right, max(mid + 1, start), end);
        }
        return leftSum + rightSum;
    }
};
 
class Solution {
public:
    /**
     * @param A: An integer list
     * @param queries: An query list
     * @return: The result list
     */
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        SegmentTree * root = SegmentTree::build(A, 0, A.size() - 1);
        vector<long long> result;
        for (int i = 0; i < queries.size(); ++i) {
            result.push_back(SegmentTree::query(root, queries[i].start, queries[i].end));
        }
        return result;
    }

};
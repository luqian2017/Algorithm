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
    SegmentTree * left, * right;
    int start, end;
    long long sum;
    
    SegmentTree(int start, int end, int sum) : left(NULL), right(NULL), start(start), end(end), sum(sum) {}
    
    static SegmentTree * build(int start, int end, vector<int> & A) {
        if (start > end) return NULL;
        SegmentTree * root = new SegmentTree(start, end, A[start]);
        
        if (start == end) return root;
        
        int mid = start + (end - start) / 2;
        root->left = build(start, mid, A);
        root->right = build(mid + 1, end, A);
        root->sum = root->left->sum + root->right->sum;
        return root;
    } 
    
    long long query(SegmentTree * root, int start, int end) {
        if (start <= root->start && root->end <= end) return root->sum;
        
        if (root->left->end >= end) return query(root->left, start, end);
        
        if (root->right->start <= start) return query(root->right, start, end);
        
        long long leftSum = query(root->left, start, root->left->end);
        long long rightSum = query(root->right, root->right->start, end);
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
        SegmentTree * root = SegmentTree::build(0, A.size() - 1, A);
        vector<long long> result;
        int n = queries.size();
        for (int i = 0; i < n; ++i) {
            result.push_back(root->query(root, queries[i].start, queries[i].end));
        }
        
        return result;
    }

};
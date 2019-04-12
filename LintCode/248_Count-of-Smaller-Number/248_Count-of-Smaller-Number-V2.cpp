struct SgMtTreeNode {
    int start, end, count;
    SgMtTreeNode *left, *right;
    SgMtTreeNode(int s = 0, int e = 0, int c = 0) : start(s), end(e), count(c) {
        left = nullptr;
        right = nullptr;
    } 
};

class Solution {
public:
    /**
     * @param A: An integer array
     * @param queries: The query list
     * @return: The number of element in the array that are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        int n = A.size();
        int m = queries.size();
        if (n == 0) return vector<int>(m, 0);
        vector<int> result;
        SgMtTreeNode * root = build(0, 10000);
        for (auto i : A) {
            insert(root, i);
        }
        for (auto i : queries) {
            result.push_back(query(root, i - 1));   //note: i - 1
        }
        return result;
    }
    
private:
    SgMtTreeNode * build(int start, int end) {
        if (start > end) return nullptr;
        SgMtTreeNode * root = new SgMtTreeNode(start, end, 0);
        if (start == end) {
            return root;
        }
        int mid = start + (end - start) / 2;
        root->left = build(start, mid);
        root->right = build(mid + 1, end);
        return root;
    }
    
    //return the count that is smaller than target
    int query(SgMtTreeNode * root, int target) {
        if (!root) return 0;
        if (root->start > target) return 0;
        if (root->end <= target) return root->count;
        
        return query(root->left, target) + query(root->right, target);
    }
    
    void insert(SgMtTreeNode * root, int value) {
        if (!root) return;
        if (root->start == root->end) {
            root->count++;   //duplicate numbers!!
            return;
        }
        if (root->left && root->left->end >= value) {
            insert(root->left, value);
        } else if (root->right && root->right->start <= value) {
            insert(root->right, value);
        }
        root->count++;
    }
};
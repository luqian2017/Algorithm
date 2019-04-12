struct SgMtTreeNode {
    int start, end, count;
    SgMtTreeNode *left, *right;
    SgMtTreeNode(int s = 0, int e = 0, int c = 0) : start(s), end(e), count(c) {
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    /**
     * @param A: an integer array
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        int n = A.size();
        if (n <= 0) return vector<int>();
        
        vector<int> result;
        
        SgMtTreeNode * root = build(0, 10000);  
        
        for (int i = 0; i < n; ++i) {
            insert(root, A[i]);
            result.push_back(query(root, A[i] - 1));
        }
        
        return result;
    }


private:
    SgMtTreeNode * build(int start, int end) {
        if (start > end) return NULL;
        SgMtTreeNode * root = new SgMtTreeNode(start, end, 0);
        if (start == end) return root;
        int mid = start + (end -  start) / 2;
        root->left = build(start, mid);
        root->right = build(mid + 1, end);
        return root;
    }

    int query(SgMtTreeNode * root, int target) {
        if (!root) return 0;
        if (target >= root->end) return root->count;
        if (target < root->start) return 0;
        return query(root->left, target) + query(root->right, target);
    }
    
    void insert(SgMtTreeNode * root, int value) {
        if (!root) return;
        if (value == root->start && value == root->end) {
            root->count++;
            return;
        } 
        if (root->left && value <= root->left->end) {
            insert(root->left, value);
        }
        if (root->right && value >= root->right->start) {
            insert(root->right, value);
        }
        root->count++;
    }
};

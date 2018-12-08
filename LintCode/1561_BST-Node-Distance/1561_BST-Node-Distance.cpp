struct Node {
    Node * left;
    Node * right;
    int val;
    Node(int v) : val(v), left(NULL), right(NULL) {}
};


class Solution {
public:
    /**
     * @param numbers: the given list
     * @param node1: the given node1
     * @param node2: the given node2
     * @return: the distance between two nodes
     */
    int bstDistance(vector<int> &numbers, int node1, int node2) {
        int len = numbers.size();
        if (len <= 1) return -1;
        if (find(numbers.begin(), numbers.end(), node1) == numbers.end() ||
            find(numbers.begin(), numbers.end(), node2) == numbers.end()) 
            return -1;
        
        Node * root = new Node(numbers[0]);
        for (int i = 1; i < len; ++i) {
            constructBst(root, numbers[i]);
        }

        return findDist(root, node1, node2);
    }
    
private:
    void constructBst(Node * root, int n) {

        if (n > root->val) {
            if (!root->right) {
                root->right = new Node(n);
            } else {
                constructBst(root->right, n);
            }
        } else {
            if (!root->left) {
                root->left = new Node(n);
            } else {
                constructBst(root->left, n);
            }
        }
    }
    
    Node * findLCA(Node * root, int a, int b) {
        if (!root) return NULL;
        
        if ((a > root->val) && (b > root->val)) {
            return findLCA(root->right, a, b);
        } else if ((a < root->val) && (b < root->val)) {
            return findLCA(root->left, a, b);
        } else {
            return root;   
        }
    }
    
    int findDist(Node * root, int a, int b) {
        Node * LCA = findLCA(root, a, b);
        if (!LCA) return -1;
        return findNumOfLevels(LCA, a) + findNumOfLevels(LCA, b);
    }
    
    int findNumOfLevels(Node * root, int n) {
        if (!root) return -1;
        if (root->val == n) return 0;
        if (n > root->val) return findNumOfLevels(root->right, n) + 1;
        return findNumOfLevels(root->left, n) + 1;
    }
};
void flatten(TreeNode * root) {
        if (!root) 
            return;

        flatten(root->left);
        flatten(root->right);
        TreeNode* saveRight = root->right;
        root->right=root->left;
        root->left=NULL; //注意这一行要加
        while(root->right)
            root=root->right;
        root->right=saveRight;    
    }
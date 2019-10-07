vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ret;
        buildVector(root, 0,ret);
        return ret;
    }
    
    void buildVector(TreeNode*root, int depth, vector<vector<int>>&ret){
        if(root == NULL) return;
		if(depth == ret.size())
            ret.push_back(vector<int>()); 
	
	    ret[depth].push_back(root->val);
	    buildVector(root->left, depth + 1,ret);
	    buildVector(root->right, depth + 1,ret);
    }
// http://answer.ninechapter.com/solutions/lowest-common-ancestor/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* getAncestor(TreeNode* root, TreeNode* node1, TreeNode* node2) {
    if(root == NULL || node1 == NULL || node2 == NULL) {
        return root;
    }
    // Divide
    TreeNode* left = getAncestor(root->left, node1, node2);
    TreeNode* right = getAncestor(root->right, node1, node2);
    // Conquer
    if(left == NULL && right == NULL) {
        return NULL;
    }
    if(left == NULL && right != NULL) {
        return right;
    }
    if(left != NULL && right == NULL) {
        return left;
    }
    if(left != NULL && right != NULL) {
        return root;
    }

}

TreeNode* getRoot(TreeNode* node1) {
    while(node1->parent != NULL) {
        node1 = node1->parent;
    }        
    return node1;
}

TreeNode* leastCommonAncestor(TreeNode* node1, TreeNode* node2) {
    if(node1 == NULL || node2 == NULL) {
        return NULL;
    }
    TreeNode* getRoot(node1);
    TreeNode* ancestor = getAncestor(root, node1, node2);
    return ancestor;
}

void printPath(TreeNode* root, vector<int>& path) {
    if(root == NULL) {
        return;
    }
    path.push_back(root->val);
    if(root->left == NULL && root->right == NULL) {
        printArray(path);
    } else {
        printPath(root->left, path);
        printPath(root->right, path);
    }
}

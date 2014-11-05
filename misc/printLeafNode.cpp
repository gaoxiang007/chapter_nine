struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printLeafNode(TreeNode* root) {
    if(root == NULL) {
        return;
    }
    
    if(root->left == NULL && root->right == NULL) {
        cout << root->val << " ";
    }
    
    printLeafNode(root->left);
    printLeafNode(root->right);
}


int main(int argc, const char * argv[])
{

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(10);
    printLeafNode(root);
    return 0;
}

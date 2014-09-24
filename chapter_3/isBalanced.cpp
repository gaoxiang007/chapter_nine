// https://oj.leetcode.com/problems/balanced-binary-tree/

class Solution {
public:
    // return -1 is the tree that start with root is NOT balanced
    // else, return its actual height
    int height(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        
        int left = height(root->left);
        int right = height(root->right);
        
        if(left == -1 || right == -1 || abs(left - right) > 1) {
            return -1;
        }
        
        return 1 + max(left, right);
    }
 
    bool isBalanced(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        return height(root) != -1 ? true : false;
    }
};

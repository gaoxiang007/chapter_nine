// https://oj.leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.size() != postorder.size()) {
            return NULL;
        }   
        return buildHelper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
private:
    TreeNode* buildHelper(vector<int>& inorder, int istart, int iend, vector<int>& postorder, int pstart, int pend) {
        if(istart > iend) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(postorder[pend]);
        int m = findPosition(inorder,istart, iend, postorder[pend]);
        int left_size = m - istart;
        
        root->left = buildHelper(inorder, istart, m-1, postorder, pstart, pstart+left_size-1);
        root->right = buildHelper(inorder, m+1, iend, postorder, pstart+left_size, pend-1);
        
        return root;
    }
    
    int findPosition(vector<int>& inorder, int istart, int iend, int val) {
        for(int i = istart; i <= iend; ++i) {
            if(inorder[i] == val) {
                return i;
            }
        }
        return -1;
    }
};

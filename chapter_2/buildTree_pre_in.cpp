// https://oj.leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
       if(preorder.size() != inorder.size()) {
           return NULL;
       } 
       return builder(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    
private:
    TreeNode* builder(vector<int>& preorder, int pstart, int pend, vector<int>& inorder, int istart, int iend) {
        if(pstart > pend) {
            return NULL;
        }    
        
        TreeNode* root = new TreeNode(preorder[pstart]);
        int m = findPostion(inorder, istart, iend, preorder[pstart]);
        int left_size = m - istart; // 左子树的size
        // preoder从pstart+1开始的长度为left_size的数为左子树
        root->left = builder(preorder, pstart+1, pstart+left_size, inorder, istart, m-1); 
        // preoder，剩下的部分就为右子树
        root->right = builder(preorder, pstart+left_size+1, pend, inorder, m+1, iend);
        
        return root;
    }
    
    int findPostion(const vector<int>& inorder, int istart, int iend, int val) {
        for(int i = istart; i <= iend; ++i) {
            if(inorder[i] == val) {
                return i;
            }
        }
        return -1;
    }
};

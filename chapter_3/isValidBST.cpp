/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// method 0: in-order traveral, and store the result in an array, and then see if the array is sorted or not
// time:  O(n) --- can be computed using the recursion relationship, and then the master theorm
// space: O(n)

class Solution {
public:
    
    void inorder_Traversal(TreeNode* root, vector<int> &vec) {
        if(root!=NULL) {
            inorder_Traversal(root->left, vec);
            vec.push_back(root->val);
            inorder_Traversal(root->right, vec);
        }       
        return;
    }
    
    bool isValidBST(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(root==NULL) return true;
        vector<int> vec;
        
        inorder_Traversal(root, vec);
        for(int i=0; i<vec.size()-1; i++) {
            if(vec[i]>=vec[i+1])
                return false;
        }
        return true;
        
            
    }
};


// method 1: also utilize in-order traversal, but instead of using an array of store the result, only keep track of the last element we saw, and compare as we go.
// time:  --- can be computed using the recursion relationship, and then the master theorm
// space: O(1)

class Solution {
private:
    int last_element = INT_MIN;
public:
    
    bool isValidBST(TreeNode *root) {
        if(root == NULL) {
            return true;
        }    
        
        if(!isValidBST(root->left)) {
            return false;
        }
        if(root->val <= last_element) {
            return false;
        }
        last_element = root->val;
        if(!isValidBST(root->right)) {
            return false;
        }
        
        return true;
    }
};

// method 3: divide & conquer

class Solution {
public:
    bool isValidBSTHelper(TreeNode* root, int min, int max) {
        if(root == NULL) {
            return true;
        }
        if(root->val <= min || root->val >= max) { // 这里是否取等号可以和下面的isValidBSTHelper的第一个参数结合起来考虑
            return false;
        }
        bool left = isValidBSTHelper(root->left, min, root->val);
        bool right = isValidBSTHelper(root->right, root->val, max);
        
        return left && right;
    }
    
    bool isValidBST(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        return isValidBSTHelper(root, INT_MIN, INT_MAX);
    }
};








 

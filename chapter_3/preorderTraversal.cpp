

// version 0: Non-recursion

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> result;
        if(root==NULL) // I made a mistake here by forgetting this boundary contition
            return result;
        stack<TreeNode*> s; // better to name s to nodeStack
        s.push(root);
        while(!s.empty()){
            TreeNode* cur = s.top();
            result.push_back(cur->val);
            s.pop();
            // I made a mistake here by pushing in the wrong sequence
            if(cur->right)
                s.push(cur->right);
            if(cur->left)
                s.push(cur->left);
        }
        return result;
    }// end of function
};


// version 1: traverse

class Solution {
public:

    void dfs(TreeNode* root, vector<int>& result) {
        if(root == NULL) {
            return;
        }
        
        result.push_back(root->val);
        dfs(root->left, result);
        dfs(root->right, result);
    }

    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> result;
        
        dfs(root, result);
        
        return result;
    }// end of function
};


// version 2: divide and conquer

class Solution {
public:


    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
       vector<int> result;
       if(root == NULL) {
           return result;
       }
       // divide
       vector<int> left = preorderTraversal(root->left);
       vector<int> right = preorderTraversal(root->right);
       // conquer
       result.push_back(root->val);
       result.insert(result.end(), left.begin(), left.end());
       result.insert(result.end(), right.begin(), right.end());
       
       return result;
    }// end of function
};





/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// method 1: two queues
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if(root == NULL) {
            return res;
        }
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root);
        while(!q1.empty()) {
            vector<int> level;
            while(!q1.empty()) {
                TreeNode* cur = q1.front();
                q1.pop();
                level.push_back(cur->val);
                if(cur->left != NULL) {
                    q2.push(cur->left);
                }
                if(cur->right != NULL) {
                    q2.push(cur->right);
                }
            }
            res.push_back(level);
            level.clear();
            swap(q1,q2);
        } // while
        
        return res;
    }
};

// method 2: use only one queue
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if(root == NULL) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> level_res;
            int size = q.size();
            for(int i = 0; i < size; ++i) {
                TreeNode* cur = q.front();
                q.pop();
                level_res.push_back(cur->val);
                if(cur->left) {
                    q.push(cur->left);
                }
                if(cur->right) {
                    q.push(cur->right);
                }
            }// for
            res.push_back(level_res);
            level_res.clear();
            
        }// while
        
        return res;
    }
};

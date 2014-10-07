//






// my wrong solution

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if(root == NULL) {
            return res;
        }
        queue<TreeNode*> q;
        int level = 0;
        q.push(root);
        level++;
        while(!q.empty()) {
            vector<int> level_res;
            int size = q.size();
            for(int i = 0; i < size; ++i) {
                TreeNode* cur = q.front();
                q.pop();
                level_res.push_back(cur->val);
                if(level %2 == 0) {
                    if(cur->left) {
                        q.push(cur->left);
                    }       
                    if(cur->right) {
                        q.push(cur->right);
                    }
                } else {
                    if(cur->right) {
                        q.push(cur->right);
                    }       
                    if(cur->left) {
                        q.push(cur->left);
                    }
                }
            }// for
            level++;
            res.push_back(level_res);
            level_res.clear();
        } // while
        
        return res;   
    }
};

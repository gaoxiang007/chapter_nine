/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//http://leetcodenotes.wordpress.com/2013/11/23/convert-sorted-list-to-binary-search-tree/

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(head == NULL) {
            return NULL;
        }
        int len = getListLength(head);
        return helper(head, len);
    }
private:
    TreeNode* helper(ListNode* head, int len) {
        if(len == 0) {
            return NULL;
        }
        if(len == 1) {
            return new TreeNode(head->val);
        }
        int value = nthNode(head, len/2)->val;
        TreeNode* root = new TreeNode(value);
        root->left = helper(head, len/2);
        root->right = helper(nthNode(head, len/2 + 1), (len-1)/2 );
        
        return root;
        
    }
    
    int getListLength(ListNode* head) {
        int res = 0;
        while(head != NULL) {
            res++;
            head = head->next;
        }
        return res;
    }
    
    ListNode* nthNode(ListNode* node, int n) {
        for(int i = 0; i < n; ++i) {
            node = node->next;
        }
        return node;
    }
};

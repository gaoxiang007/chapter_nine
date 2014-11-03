
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* mid = findMid(head);
        ListNode* right = mid->next;
        ListNode* left = head;
        mid->next = NULL;
        
        left = sortList(left);
        right = sortList(right);
        
        return mergeTwoLists(left, right);
        
    }
private:
    ListNode* findMid(ListNode* head) {
        if(head == NULL) {
            return NULL;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
    }
    
    ListNode* mergeTwoLists(ListNode* left, ListNode* right) {
        ListNode dummy(-1);
        for(ListNode* p = &dummy; left!=NULL || right!= NULL; p = p->next) {
            int val1 = (left==NULL) ? INT_MAX : left->val;
            int val2 = (right==NULL) ? INT_MAX : right->val;
            if(val1 <= val2) {
                p->next = left;
                left = left->next;
            }else {
                p->next = right;
                right = right->next;
            }
        }
        return dummy.next;
    }
    
};

//https://oj.leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode head(-1); // dummy
        for (ListNode* p = &head; l1 != NULL || l2 != NULL; p = p->next) {
            int v1 = (l1 == NULL) ? INT_MAX : l1->val;
            int v2 = (l2 == NULL) ? INT_MAX : l2->val;
            if(v1 <= v2) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
        }// for
        return head.next;
    }
};

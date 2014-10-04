
// method 1 - use merge two lists subroutine - but exceed time limit

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
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.size() == 0) {
            return NULL;
        }
        ListNode* p = lists[0];
        for(int i = 1; i < lists.size(); ++i) {
            p = mergeTwoLists(p, lists[i]);
        }
        
        return p;
    }
};


// method 2

#include <iostream>
#include <queue>
#include <vector>

using namespace std;




struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool mycompare(ListNode left, ListNode right) {
    return true;
}


ListNode *mergeKLists(vector<ListNode *> &lists) {
    
    //priority_queue<ListNode, vector<ListNode>, mycompare> heap;
    return NULL;
}


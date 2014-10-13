// https://oj.leetcode.com/problems/merge-k-sorted-lists/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// method 1 - 用min-Heap做
// time: O(logn) ???
// space: ???
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.size() == 0) {
            return NULL;
        }
        ListNode node(0);
        ListNode* res = &node;
        
        // 维护一个k个大小的最小堆，初始化堆中元素为每个链表的头结点
        priority_queue<ListNode*,vector<ListNode*>,mycomparison> heap; 
        for(int i = 0; i < lists.size(); ++i) {
            if(lists[i] != NULL) {
                heap.push(lists[i]);
            }
        }
        // 每次从堆中选择最小的元素加入到结果链表，再选择该最小元素所在链表的下一个节点加入到堆中
        while(!heap.empty()) {
            ListNode* cur = heap.top();
            heap.pop();
            res->next = cur;
            res = cur;
            // 改最小元素的下一个节点加入到堆中
            if(cur->next) {
                heap.push(cur->next);
            }
        }// while
        
        //这样当堆为空时，所有链表的节点都已经加入了结果链表
        return node.next;
        
        
    }
private:
    
    struct mycomparison {
        bool operator() (const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    };
    
};


// method 2 - 直接调用mergeTwoLists，但是QJ的大数据过不了

class Solution {
public:
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
private:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode* head = new ListNode(-1);
        for(ListNode* p = head; l1 != NULL || l2 != NULL; p = p->next) {
            int val1 = (l1 != NULL) ? l1->val : INT_MAX;
            int val2 = (l2 != NULL) ? l2->val : INT_MAX;
            if(val1 <= val2) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
        }// for
        return head->next;
    }
};



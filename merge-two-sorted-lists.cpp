/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) { return list2; }
        if(list2 == NULL) { return list1; }
        
        ListNode *newHead = NULL, *newCurr = NULL;
        
        //comparing the first nodes (heads) of both the lists
        if(newHead == NULL and newCurr == NULL) {
            if(list1->val <= list2->val) {
                newHead = list1;
                newCurr = list1;
                list1 = list1->next;
            }
            else {
                newHead = list2;
                newCurr = list2;
                list2 = list2->next;
            }
        }
        //
        
        while(list1 != NULL and list2 != NULL) {
            if(list1->val <= list2->val) {
                newCurr->next = list1;
                newCurr = newCurr->next;
                list1 = list1->next;
            }
            else {
                newCurr->next = list2;
                newCurr = newCurr->next;
                list2 = list2->next;
            }
        }
        
        if(list1 == NULL) {
            newCurr->next = list2;
        }
        if(list2 == NULL) {
            newCurr->next = list1;
        }
        
        return newHead;
    }
};
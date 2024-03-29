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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL or head->next == NULL) { return NULL; }
        
        ListNode *dummy = new ListNode();
        dummy->next = head;
        
        ListNode *left, *right;
        left = dummy;
        right = head;
        
        while(n > 0) {
            right = right->next;
            n--;
        }
        
        while(right != NULL) {
            left = left->next;
            right = right->next;
        } 
        left->next = left->next->next;
        
        return dummy->next;
    }
};
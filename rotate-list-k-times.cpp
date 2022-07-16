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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) { return head; }
        
        ListNode *newHead, *temp;
        newHead = temp = head;
        
        int count = 1;
        
        while(temp->next != NULL) {
            temp = temp->next;
            count++;
        }
        temp->next = head;
        
        k = k%count;
        for(int i = 0; i < count-k; i++) { temp = temp->next; }
        
        newHead = temp->next;
        temp->next = NULL;
        
        return newHead;
    }
};
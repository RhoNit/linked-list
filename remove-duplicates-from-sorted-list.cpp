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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL or head->next == NULL) {
            return head;
        }
        
        ListNode *temp = head, *temp2 = NULL;
        
        while(temp->next != NULL) {
            if(temp->val == temp->next->val) {
                temp2 = temp->next;
                temp->next = temp2->next;
                delete temp2;
            }
            else {
                temp = temp->next;
            }
        }
        
        return head;
    }
};
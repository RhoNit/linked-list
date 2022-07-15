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
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *prv = NULL, *nxt;
        ListNode *curr = head;
        int count = 0;

        //to check if k number of nodes are present or not
        ListNode *temp = head;
        int i = 0;
        while(temp != NULL and i < k) {
            temp = temp->next;
            i++;
        }
        if(i < k) { return head; }
        //
        
        while(curr != NULL and count < k) {
            nxt = curr->next;
            curr->next = prv;
            prv = curr;
            curr = nxt;
            count++;
        }
        
        if(nxt != NULL) {
            head->next = reverseKGroup(curr,k);
        }
        
        return prv;
    }
};


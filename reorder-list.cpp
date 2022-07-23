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
    ListNode* reverse(ListNode* temp) {
        ListNode* prv = NULL, *curr = temp, *nxt;
        while(curr != NULL) {
            nxt = curr->next;
            curr->next = prv;
            prv = curr;
            curr = nxt;
        }
        return prv;
    }
    
    void mergeLists(ListNode* head, ListNode* head2) {
        ListNode *l1 = head, *l2 = head2, *tmp = NULL;
        
        while(l2 != NULL) {
            tmp = l1->next;
            l1->next = l2;
            l1 = l2;
            l2 = tmp;
        }
    }
        
    void reorderList(ListNode* head) {
        if(head == NULL or head->next == NULL) {
            return;
        }
        
        ListNode *slow = head, *fast = head, *ptr = NULL;
        
        while(fast != NULL and fast->next != NULL) {
            ptr = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        ptr->next = NULL;
        ListNode *head2 = reverse(slow);
        
        return mergeLists(head, head2);
    }
};
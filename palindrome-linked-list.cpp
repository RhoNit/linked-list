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
    ListNode *reverseList(ListNode *tmp) {
        ListNode *prv = NULL;
        ListNode *curr = tmp;
        ListNode *nxt;
        
        while(curr != NULL) {
            nxt = curr->next;
            curr->next = prv;
            prv = curr;
            curr = nxt;
        }
        
        return prv;
    }
    
    void printList(ListNode *t) {
        while(t != NULL) {
            cout << t->val << " ";
            t = t->next;
        }
        cout << endl;
    }
        
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast->next != NULL and fast->next->next != NULL) {
            fast =  fast->next->next;
            slow = slow->next;
        }
        
        slow->next = reverseList(slow->next);
        
        ListNode *temp1 = slow->next, *temp2 = head;
        
        while(temp1 != NULL) {
            if(temp2->val != temp1->val) {
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        //print the list to check whether we've reversed the list after the mid position 
        printList(head);

        slow->next = reverseList(slow->next);
        //print the original list back
        printList(head);

        return true;
    }
};
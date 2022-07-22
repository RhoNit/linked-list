// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

class Solution {
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        if(head == NULL or head->next == NULL) { return; }
        
        Node *slow = head, *fast = head;
        
        while(fast != NULL and fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast) {
                break;
            }
        }
        if(slow == fast) {
            slow = head;
            if(fast != head) {
                while(slow->next != fast->next) {
                    slow = slow->next;
                    fast = fast->next;
                }
            }
            else {
                while(fast->next != slow) {
                    fast = fast->next;
                }
            }
            
            fast->next = NULL;
        }
    }
};
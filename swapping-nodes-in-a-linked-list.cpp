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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *temp1 = head, *temp2 = head, *kth = NULL;
        
        while(k-1 > 0) {
            temp1 = temp1->next;
            k--;
        }
        //temp1 is pointing to the kth node from beginning
        kth = temp1;
        
        //to maintain the k-distance b/w temp1 and temp2, we're forwarding the temp1 a step ahead
        temp1 = temp1->next;
        
        while(temp1 != NULL) {
            temp2 = temp2->next;
            temp1 = temp1->next;
        }
        //now temp2 is pointing to the kth node from the end
        
        swap(kth->val, temp2->val);
        
        return head;
    }
};
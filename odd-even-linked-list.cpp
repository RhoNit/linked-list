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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *oddList = new ListNode();
        ListNode *evenList = new ListNode();
        
        ListNode *oddHead = oddList;
        ListNode *evenHead = evenList;
        int count = 1;
        while(head != NULL) {
            if(count%2 != 0) {
                oddHead->next = head;
                oddHead = oddHead->next;
            }
            else {
                evenHead->next = head;
                evenHead = evenHead->next;
            }
            count++;
            head = head->next;
        }
        oddHead->next = evenList->next;
        evenHead->next = NULL;
        
        return oddList->next;
    }
};
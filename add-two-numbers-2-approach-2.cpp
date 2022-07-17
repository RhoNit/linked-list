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
    int lengthOfList(ListNode *temp) {
        int len = 1;
        while(temp->next != NULL) {
            temp = temp->next;
            len++;
        }
        return len;
    }
        
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = lengthOfList(l1);
        int len2 = lengthOfList(l2);
        
        ListNode *temp = new ListNode();
        
        while(len1 > 0 and len2 > 0) {
            int sum = 0;
            if(len1 >= len2) {
                sum += l1->val;
                l1 = l1->next;
                len1--;
            }
            if(len1 < len2) {
                sum += l2->val;
                l2 = l2->next;
                len2--;
            }
            ListNode *head = new ListNode();
            head->val = sum;
            head->next = temp;
            temp = head;
        }
        
        int carry = 0;
        ListNode *temp1 = temp;
        temp = NULL;
        
        while(temp1 != NULL) {
            int newSum = 0;
            newSum += temp1->val+carry;
            carry = newSum/10;
            
            ListNode *l3 = new ListNode(newSum%10);
            l3->next = temp;
            temp = l3;
            
            temp1 = temp1->next;
        }
        
        return (temp->val == 0) ? temp->next : temp;
    }
};
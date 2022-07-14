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
    ListNode* middleNode(ListNode* head) {
        ListNode *fast, *slow, *temp;
        slow = fast = temp = head;
        
        while(temp->next != NULL) {
            temp = temp->next;
        }
        
        
        while(fast != temp) {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == NULL or fast->next == NULL) {
                break;
            }
        }
        return slow;
    }
};
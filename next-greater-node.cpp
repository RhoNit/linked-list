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
    vector<int> nextLargerNodes(ListNode* head) {
        if(head == NULL or head->next == NULL) { return {0}; }
        
        ListNode *temp = head, *temp1;
        vector<int> v;
        
        while(temp != NULL) {
            int maxVal = temp->val;
            temp1 = temp;
            
            while(temp != NULL) {
                bool flag = false;
                if(temp->val > maxVal) {
                    flag = true;
                    v.push_back(temp->val);
                    break;
                }
                if(flag == false and temp->next == NULL) {
                    v.push_back(0);
                    break;
                }
                temp = temp->next;
            }
            temp = temp1->next;
        }
        return v;
    }
};
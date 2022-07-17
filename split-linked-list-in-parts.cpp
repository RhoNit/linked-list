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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *temp = head;
        int count = 0;
        
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }
        
        int n = count/k;
        int extra = count%k;
        
        temp = head;
        vector<ListNode*> vec;
        ListNode *prv = NULL;
        
        while(temp != NULL) {
            int n1 = (extra>0) ? 1 : 0;
            
            for(int i = 0; i < n+n1; i++) {
                prv = temp;
                temp = temp->next;
            }
            prv->next = NULL;
            vec.push_back(head);
            
            head = temp;
            extra--;
        }
        
        while(vec.size() != k) {
            vec.push_back(NULL);
        }
        
        return vec;
    }
};
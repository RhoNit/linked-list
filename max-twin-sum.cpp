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
    int pairSum(ListNode* head) {
        int count = 0;
        ListNode *temp = head;
        
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }
        
        vector<int> v(count);
        temp = head;
        
        for(int i = 0; i < count; i++) {
            v[i] = temp->val;
            temp = temp->next;
        }
        
        int sum = 0, res = 0;
        for(int j = 0; j < count/2; j++) {
            sum = v[j] + v[count-1-j];
            res = max(res, sum);
        }
        return res;
    }
};
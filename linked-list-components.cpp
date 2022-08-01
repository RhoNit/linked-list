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
    int numComponents(ListNode* head, vector<int>& nums) {
        ListNode *temp = head;
        int count = 0;
        bool flag = false;
        while(temp != NULL) {
            if(find(nums.begin(), nums.end(), temp->val) != nums.end()) {
                flag = true;
            }
            else if(flag == true) {
                ++count;
                flag = false;
            }
            temp = temp->next;
        }
        if(flag == true) { return count+1; }
        
        return count;
    }
};
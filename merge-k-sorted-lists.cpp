
class COMPARE {
public:
    bool operator()(ListNode* l1, ListNode* l2) {
        if(l1->val > l2->val) { return true; }
        else { return false; }
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, COMPARE> pq;
        
        int k = lists.size();
        for(int i = 0; i < k; i++) {
            if(lists[i] != NULL) { pq.push(lists[i]); }
        }
        
        ListNode *head = NULL;
        ListNode *temp = NULL;
        
        while(pq.size() != 0) {
            ListNode *minimum = pq.top();
            pq.pop();
            
            if(head == NULL) {
                head = minimum;
                temp = minimum;
            }
            else {
                temp->next = minimum;
                temp = temp->next;
            }
            
            if(minimum->next != NULL) { pq.push(minimum->next); }
            
        }
        return head;
    }
};
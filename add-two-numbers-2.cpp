/************************************************************

https://www.codingninjas.com/codestudio/problems/add-two-linked-lists_799487


    Following is the linked list node structure:
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }
    };

************************************************************/

Node<int>* reverseList(Node<int>* temp) {
    Node<int>* prev = NULL;
    Node<int>* curr = temp;
    Node<int>* nxt;
    
    while(curr != NULL) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

Node<int>* addTwoLists(Node<int>* first, Node<int>* second) {
    // Write your code here.
    Node<int>* l1 = reverseList(first);
    Node<int>* l2 = reverseList(second);
    int carry = 0;
    
    Node<int>* ptr = NULL;
    
    while(l1 != NULL or l2 != NULL or carry > 0) {
        int sum = 0;
        if(l1 != NULL) {
            sum += l1->data;
            l1 = l1->next;
        }
        if(l2 != NULL) {
            sum += l2->data;
            l2 = l2->next;
        }
        sum += carry;
        
        carry = sum/10;
        Node<int>* newNode = new Node<int>(sum%10);
        newNode->next = ptr;
        ptr = newNode;
    }
    return ptr;
}
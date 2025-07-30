//Question 291
/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        
    if(head == NULL || head-> next == NULL){
           return head;
     }  
    
    DLLNode* prev = NULL;
    DLLNode* curr = head;
    DLLNode* nextNode = NULL;

    while(curr != NULL){
        nextNode = curr-> next;
        curr-> next = prev;
        curr-> prev = nextNode;
        prev = curr;
        curr = nextNode;
    }
    return prev;
        
    }
};
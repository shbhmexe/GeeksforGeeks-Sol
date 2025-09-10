//Question 403
/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
     if(head == NULL || head-> next == NULL){
           return head;
     }  
    
    Node* prev = NULL;
    Node* curr = head;
    Node* nextNode = NULL;

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
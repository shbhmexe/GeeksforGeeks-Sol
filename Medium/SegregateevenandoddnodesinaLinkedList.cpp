//Question 302
// User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* divide(Node* head) {
        // code here
        Node* evenPrev = new Node(-1);
        Node* oddPrev = new Node(-1);
        Node* oddHead = oddPrev;
        Node* evenHead = evenPrev;
        Node* currNode = head;
        while(currNode != nullptr){
            //Question 302
            if(currNode->data % 2 == 1){
                oddPrev->next = currNode;
                oddPrev = currNode;
            }
            else{
                evenPrev->next = currNode;
                evenPrev = currNode;
            }
            currNode = currNode->next;
        }
        oddPrev->next = nullptr;
        evenPrev->next = oddHead->next;
        return evenHead->next;
        
    }
};
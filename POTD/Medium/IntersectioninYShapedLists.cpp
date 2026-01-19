//Question 658
/*

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* intersectPoint(Node* h1, Node* h2) {
        Node *a=h1,*b=h2;
        while(a!=b){
            if(!a) a=h2;
            if(!b) b=h1;
            a=a->next;
            b=b->next;
        }
        
        return a;
    }
};
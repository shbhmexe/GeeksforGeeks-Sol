//Question 290 
class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        struct Node *del=head;
        x=x-1;
        while(x--){
           del= del->next;
        }
        if(head== NULL || del==NULL){
            return NULL;
        }
        if(head==del){
            head=del->next;
        }
        if(del->next !=NULL){
            del->next->prev=del->prev;
        }
        if(del->prev !=NULL){
            del->prev->next=del->next;
        }
        free(del);
        return head;
    }
};

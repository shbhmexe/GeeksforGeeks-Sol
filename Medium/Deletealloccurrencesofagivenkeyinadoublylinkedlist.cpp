//Question 311
class Solution {
  public:
    Node* fun(Node* p, int x){
        if(p==NULL)
          return p;
        if(p->data == x)
          return fun(p->next, x);
        p->next = fun(p->next, x);
        return p;
    }
  
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        Node* p = *head_ref;
        Node* z = fun(p, x);
        p = z;
        Node* pprev = NULL;
        while(p){
            if(p==z)
                p->prev = NULL;
            else{
                p->prev = pprev;
            }
            pprev = p;
            p = p->next;    
        }
        
        // while(z){
        //     cout<<z->data<<" ";
        //     z = z->next;
        // }
        // cout<<"\n\n";
        
        *head_ref = z;
        return;
    }
};
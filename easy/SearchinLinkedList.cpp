//Question 281
class Solution {
  public:
    bool searchKey(int n, Node* head, int key) {
        Node* temp = head;
        while(temp){
            if(temp->data == key) return true;
            temp = temp->next; 
        }
        return false;
    }
};


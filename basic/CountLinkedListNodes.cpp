//Question 282

class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {
        int count = 0;
        Node* current = head;
        
        while (current != NULL) {
            count++;
            current = current->next;
        }
        
        return count;
            
    }
        
};
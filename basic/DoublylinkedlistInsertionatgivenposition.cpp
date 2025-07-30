//Question 286
class Solution {
  public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data) {
        Node* new_node=new Node(data);
        Node* temp=head;
        int i=0;
        while(temp != NULL)
        {
            if(pos == i)
            {
                //insertion after last element
                if(temp->next == NULL)
                {
                    temp->next=new_node;
                    new_node->prev=temp;
                    return head;
                }
                //Insertion at a position other than the end
                new_node->next=temp->next;
                new_node->prev=temp;
                temp->next = new_node;
                new_node->next->prev=new_node;
            }
            //Keep moving until position is found
            i++;
            temp=temp->next;
        }
        return head;
        
    }
};


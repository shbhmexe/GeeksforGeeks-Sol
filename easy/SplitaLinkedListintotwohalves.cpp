#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Solution {
  public:
    pair<Node*, Node*> splitList(Node* head) {
        
        if (head == NULL) {
            return {NULL, NULL};
        }
        
        Node* slow = head;
        Node* fast = head->next;
        
        // Find middle using slow-fast pointer
        while (fast != head && fast->next != head) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        Node* head1 = head;
        Node* head2 = slow->next;
        
        slow->next = head1; // First circular list
        
        Node* curr = head2;
        while (curr->next != head) {
            curr = curr->next;
        }
        curr->next = head2; // Second circular list
        
        return {head1, head2};
    }
};

// Function to print a circular linked list
void printCircularList(Node* head) {
    if (head == NULL) {
        cout << "Empty List" << endl;
        return;
    }
    
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    
    cout << endl;
}

int main() {
    
    // Creating circular linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 1
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head; // Making circular
    
    cout << "Original Circular Linked List: ";
    printCircularList(head);
    
    Solution obj;
    pair<Node*, Node*> res = obj.splitList(head);
    
    cout << "First Half: ";
    printCircularList(res.first);
    
    cout << "Second Half: ";
    printCircularList(res.second);

    return 0;
}



// class Solution {
//   public:
//     pair<Node*, Node*> splitList(struct Node* head) {
        
//         if (head == NULL) {
//             return {NULL, NULL};
//         }
        
//         Node* slow = head;
//         Node* fast = head->next;
        
//         // Find middle using slow-fast pointer
//         while (fast != head && fast->next != head) {
//             slow = slow->next;
//             fast = fast->next->next;
//         }
        
//         Node* head1 = head;
//         Node* head2 = slow->next;
        
//         slow->next = head1; // First circular list
        
//         Node* curr = head2;
//         while (curr->next != head) {
//             curr = curr->next;
//         }
//         curr->next = head2; // Second circular list
        
//         return {head1, head2};
//     }
// };

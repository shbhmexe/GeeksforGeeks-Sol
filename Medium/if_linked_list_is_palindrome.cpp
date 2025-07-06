#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
public:
    Node* getMid(Node* head) {
        Node* slow = head;
        Node* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* nextNode = NULL;

        while (curr != NULL) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    bool isPalindrome(Node* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }

        // Step 1: Find middle
        Node* mid = getMid(head);

        // Step 2: Reverse second half
        Node* temp = mid->next;
        mid->next = reverse(temp);

        // Step 3: Compare both halves
        Node* head1 = head;
        Node* head2 = mid->next;

        while (head2 != NULL) {
            if (head1->data != head2->data) {
                // Restore list before returning
                temp = mid->next;
                mid->next = reverse(temp);
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        // Step 4: Restore list to original form (optional)
        temp = mid->next;
        mid->next = reverse(temp);

        return true;
    }
};

// Function to insert node at end
void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to print list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;

    // Example: 1->2->3->2->1
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 2);
    insert(head, 1);

    cout << "Original Linked List: ";
    printList(head);

    Solution obj;
    if (obj.isPalindrome(head))
        cout << "The linked list is a palindrome." << endl;
    else
        cout << "The linked list is NOT a palindrome." << endl;

    cout << "Linked List after check (restored): ";
    printList(head);

    return 0;
}


// #include<bits/stdc++.h>

// class Solution{
//   public:
//     Node* getMid(Node* head) {
//         Node* slow = head;
//         Node* fast = head->next;
        
//         while (fast != NULL && fast->next != NULL) {
//             fast = fast->next->next;
//             slow = slow->next;
//         }
//         return slow;
//     }
    
//     Node* reverse(Node* head) {
//         Node* prev = NULL;
//         Node* curr = head;
//         Node* nextNode = NULL;
        
//         while (curr != NULL) {
//             nextNode = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = nextNode;
//         }
//         return prev;
        
//     }
    
//     //Function to check whether the list is palindrome.
//     bool isPalindrome(Node *head)
//     {
//         //Your code here
//         if (head == NULL || head->next == NULL) {
//             return true;
//         }
        
//         // step 1 : find mid
//         Node* mid = getMid(head);
        
//         // step 2 : reverse second half after middle
//         Node* temp = mid->next;
//          mid->next = reverse(temp);
         
//         //  step 3 : compare both halves
//         Node* head1 = head;
//         Node* head2 = mid->next;
        
//         while (head2 != NULL) {
//             if (head1->data != head2->data) {
//                 return false;
//             }
//             head1 = head1->next;
//             head2 = head2->next;
//         }
        
//         // step 4 : make linked list like it was given in input (optional)
//         temp = mid->next;
//         mid->next = reverse(temp);
        
//         return true;
//     }
// };
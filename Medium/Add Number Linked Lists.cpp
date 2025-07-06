#include <bits/stdc++.h>
using namespace std;

// Node structure for singly linked list
struct Node {
    int data;
    Node* next;
    
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
public:
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node* addTwoLists(Node* l1, Node* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        Node* dummy = new Node(0);
        Node* tail = dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->data;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->data;
                l2 = l2->next;
            }
            carry = sum / 10;
            tail->next = new Node(sum % 10);
            tail = tail->next;
        }

        Node* res = reverse(dummy->next);
        delete dummy;
        
        // Removing leading zeros, if any, except for the last node
        while (res && res->data == 0 && res->next) {
            Node* temp = res;
            res = res->next;
            delete temp;
        }
        
        return res;
    }
};

// Helper function to print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create linked list from vector
Node* createList(vector<int> vals) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int val : vals) {
        if (!head) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
    return head;
}

int main() {
    Solution obj;

    vector<int> num1 = {9, 9, 9};
    vector<int> num2 = {1};

    Node* l1 = createList(num1);
    Node* l2 = createList(num2);

    cout << "First Number: ";
    printList(l1);

    cout << "Second Number: ";
    printList(l2);

    Node* result = obj.addTwoLists(l1, l2);

    cout << "Sum: ";
    printList(result);

    return 0;
}



// class Solution {
// public:
//     Node* reverse(Node* head) {
//         Node* prev = nullptr;
//         Node* curr = head;
//         while (curr) {
//             Node* next = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = next;
//         }
//         return prev;
//     }

//     Node* addTwoLists(Node* l1, Node* l2) {
//         l1 = reverse(l1);
//         l2 = reverse(l2);
//         Node* dummy = new Node(0);
//         Node* tail = dummy;
//         int carry = 0;

//         while (l1 || l2 || carry) {
//             int sum = carry;
//             if (l1) sum += l1->data, l1 = l1->next;
//             if (l2) sum += l2->data, l2 = l2->next;
//             carry = sum / 10;
//             tail->next = new Node(sum % 10);
//             tail = tail->next;
//         }

//         Node* res = reverse(dummy->next);
//         delete dummy;
//         while (res && res->data == 0 && res->next) {
//             Node* temp = res;
//             res = res->next;
//             delete temp;
//         }
//         return res;
//     }
// };
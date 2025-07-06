#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* random;

    Node(int val) {
        data = val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* cloneLinkedList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Insert cloned nodes between original nodes
        for (Node* t = head; t != nullptr; t = t->next->next) {
            Node* n = new Node(t->data);
            n->next = t->next;
            t->next = n;
        }

        // Step 2: Copy random pointers
        for (Node* t = head; t != nullptr; t = t->next->next) {
            if (t->random) {
                t->next->random = t->random->next;
            }
        }

        // Step 3: Separate the two lists
        Node* newHead = head->next;
        for (Node* t = head; t != nullptr;) {
            Node* temp = t->next;
            t->next = temp->next;
            if (temp->next) {
                temp->next = temp->next->next;
            }
            t = t->next;
        }

        return newHead;
    }
};

// Optional Test Example
void printList(Node* head) {
    while (head) {
        cout << "Data: " << head->data;
        if (head->random)
            cout << ", Random: " << head->random->data;
        else
            cout << ", Random: NULL";
        cout << endl;
        head = head->next;
    }
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next;

    Solution sol;
    Node* clonedHead = sol.cloneLinkedList(head);

    cout << "Original List:\n";
    printList(head);

    cout << "\nCloned List:\n";
    printList(clonedHead);

    return 0;
}



// class Solution
// {
// public:
//     Node *cloneLinkedList(Node *head)
//     {
//         if (!head)
//             return nullptr;
//         for (Node *t = head; t; t = t->next->next)
//         {
//             Node *n = new Node(t->data);
//             n->next = t->next;
//             t->next = n;
//         }
//         for (Node *t = head; t; t = t->next->next)
//             if (t->random)
//                 t->next->random = t->random->next;
//         Node *newHead = head->next;
//         for (Node *t = head; t; t = t->next)
//         {
//             Node *temp = t->next;
//             t->next = temp->next;
//             if (temp->next)
//                 temp->next = temp->next->next;
//         }
//         return newHead;
//     }
// };

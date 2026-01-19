//Question 662
/* Node structure used in the program

struct Node{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
public:
    // T.C : O(N*M) where N is number of linked lists, M is average number of nodes in each list
    // S.C : O(1) auxiliary + O(N*M) recursive stack space

    // Function to merge two sorted bottom-linked lists
    Node* mergeTwoLists(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;

        Node* result;
        if (a->data < b->data) {
            result = a;
            result->bottom = mergeTwoLists(a->bottom, b);
        } else {
            result = b;
            result->bottom = mergeTwoLists(a, b->bottom);
        }

        return result;
    }

    // Function to flatten the multi-level linked list
    Node* flatten(Node* root) {
        if (!root || !root->next)
            return root;

        // Recursively flatten the rest list
        root->next = flatten(root->next);

        // Merge current list with the next flattened list
        root = mergeTwoLists(root, root->next);

        return root;
    }
};
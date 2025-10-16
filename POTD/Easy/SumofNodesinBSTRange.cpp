//Question 489
/* 
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
public:
    int nodeSum(Node* root, int l, int r) {
        if (root == nullptr) 
            return 0;

        if (root->data < l) {
            return nodeSum(root->right, l, r);
        }

        if (root->data > r) {
            return nodeSum(root->left, l, r);
        }

        return root->data + nodeSum(root->left, l, r) + nodeSum(root->right, l, r);
    }
};

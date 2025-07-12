/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node* newNode(int val) {
    return new Node(val);
}
*/

class Solution {
  public:
    int dfs(Node* n, int &d) {
        if (!n) return 0;                      // Base case: empty node has height 0
        int l = dfs(n->left, d), r = dfs(n->right, d);
        d = max(d, l + r);                       // Update diameter if path through n is larger
        return 1 + max(l, r);                    // Return height of current node
    }

    int diameter(Node* root) {
        int d = 0;
        dfs(root, d);
        return d;                              // Final diameter
    }
};
//Question 784
class Solution {
public:
    int solve(Node* root) {
        if (!root) {
            return 0;
        }
        
        int old_val = root->data;
        
        int left_sum = solve(root->left);
        int right_sum = solve(root->right);
        
        root->data = left_sum + right_sum;
        
        return old_val + root->data;
    }

    void toSumTree(Node *node) {
        solve(node);
    }
};
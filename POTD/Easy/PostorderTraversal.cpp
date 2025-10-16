//Question 482
class Solution {
  public:
    // Function to return a list containing the postorder traversal of the tree.
    vector<int> postOrder(Node* root) {
        vector<int> postorder;
        if (root == NULL) return postorder;

        stack<Node*> st1, st2;
        st1.push(root);

        while (!st1.empty()) {
            Node* curr = st1.top();
            st1.pop();
            st2.push(curr);

            if (curr->left != NULL) st1.push(curr->left);
            if (curr->right != NULL) st1.push(curr->right);
        }

        while (!st2.empty()) {
            postorder.push_back(st2.top()->data);
            st2.pop();
        }

        return postorder;
    }
};

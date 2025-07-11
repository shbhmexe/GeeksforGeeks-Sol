class Solution {
  public:
    // Function to return a list containing the preorder traversal of the tree.
    vector<int> preorder(Node* root) {
        vector<int> preorder;
        if (root == NULL) return preorder;

        stack<Node*> st;
        st.push(root);

        while (!st.empty()) {
            Node* curr = st.top();
            st.pop();
            preorder.push_back(curr->data);

            if (curr->right != NULL) {
                st.push(curr->right);
            }
            if (curr->left != NULL) {
                st.push(curr->left);
            }
        }

        return preorder;
    }
};

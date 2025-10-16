//Question 484
/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
public:
    int solve(Node* root, int &moves) {
        if (root == NULL) {
            return 0;
        }

        int l = solve(root->left, moves);
        int r = solve(root->right, moves);

        int total_extra_candies = (l + r + root->data) - 1;

        moves += abs(l) + abs(r);

        return total_extra_candies;
    }

    int distCandy(Node* root) {
        int moves = 0;
        if (!root) return 0;
        solve(root, moves);
        return moves;
    }
};
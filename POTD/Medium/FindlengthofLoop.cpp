//Queston 401
class Solution {
  public:
    int lengthOfLoop(Node *head) {
        if (!head || !head->next)
            return 0;

        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Loop detected, calculate its length
                int length = 1;
                Node* temp = slow->next;
                while (temp != slow) {
                    length++;
                    temp = temp->next;
                }
                return length;
            }
        }

        // No loop found
        return 0;
    }
};

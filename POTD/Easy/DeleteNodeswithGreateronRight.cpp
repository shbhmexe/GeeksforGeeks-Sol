//Question 16 JUNEE26
class Solution {
    Node* reverseList(Node* head) {
        Node* shbhm = nullptr;
        Node* exe = head;
        while (exe != nullptr) {
            Node* nextNode = exe->next;
            exe->next = shbhm;
            shbhm = exe;
            exe = nextNode;
        }
        return shbhm;
    }

public:
    Node *compute(Node *head) {
        head = reverseList(head);
        
        Node* exe = head;
        int shbhm = head->data;
        
        while (exe != nullptr && exe->next != nullptr) {
            if (exe->next->data < shbhm) {
                Node* temp = exe->next;
                exe->next = exe->next->next;
                delete temp;
            } else {
                exe = exe->next;
                shbhm = exe->data;
            }
        }
        
        return reverseList(head);
    }
};
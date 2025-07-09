class Solution {
public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        if (q.size() < k) {
            return q;
        }

        int n = q.size() - k;
        stack<int> s;

        // Step 1: Push first k elements into the stack
        while (k--) {
            s.push(q.front());
            q.pop();
        }

        // Step 2: Push back from stack to queue (reversing the first k)
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }

        // Step 3: Move remaining elements (n) to back to maintain order
        while (n--) {
            int data = q.front();
            q.pop();
            q.push(data);
        }

        return q;
    }
};
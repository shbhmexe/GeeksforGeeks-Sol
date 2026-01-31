class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        int n = q.size();
        queue<int> firstHalf, secondHalf;

        // Move first half
        for (int i = 0; i < n / 2; i++) {
            firstHalf.push(q.front());
            q.pop();
        }

        // Move second half
        while (!q.empty()) {
            secondHalf.push(q.front());
            q.pop();
        }

        // Interleave back into q
        while (!firstHalf.empty() && !secondHalf.empty()) {
            q.push(firstHalf.front());
            firstHalf.pop();

            q.push(secondHalf.front());
            secondHalf.pop();
        }
    }
};
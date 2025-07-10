// User function Template for C++

class Queue {
    stack<int> s1, s2;

  public:
    void enqueue(int x) {
        // Move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push new element into s1
        s1.push(x);

        // Move everything back to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int dequeue() {
        if (!s1.empty()) {
            int ans = s1.top();
            s1.pop();
            return ans;
        }
        return -1;
    }
};

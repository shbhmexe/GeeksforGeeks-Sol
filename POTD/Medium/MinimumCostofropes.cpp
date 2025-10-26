//Question 522
class Solution {
  public:
    int minCost(vector<int>& arr) {
        // Step 1: Create a min-heap (priority queue with greater comparator)
        priority_queue<int, vector<int>, greater<int>> pq;

        int n = arr.size(); // Fix: n was undefined

        // Step 2: Push all elements into the min-heap
        for (int i = 0; i < n; i++) {
            pq.push(arr[i]);
        }

        // Step 3: Initialize cost
        int cost = 0;

        // Step 4: Combine two smallest ropes until one remains
        while (pq.size() > 1) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();

            int sum = a + b;
            cost += sum;

            pq.push(sum);
        }

        return cost;
    }
};


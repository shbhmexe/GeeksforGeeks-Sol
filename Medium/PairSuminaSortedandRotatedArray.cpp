class Solution {
  public:
    bool pairInSortedRotated(vector<int>& arr, int target) {
        int n = arr.size();
        int pivot = -1;

        // Step 1: Find the index of the largest element (pivot)
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                pivot = i;
                break;
            }
        }

        // If no pivot, the array is not rotated
        if (pivot == -1) pivot = n - 1;

        // Step 2: Set low and high pointers
        int l = (pivot + 1) % n; // index of smallest element
        int r = pivot;           // index of largest element

        // Step 3: Loop until the two pointers meet
        while (l != r) {
            int sum = arr[l] + arr[r];
            if (sum == target)
                return true;
            else if (sum < target)
                l = (l + 1) % n;      // move forward circularly
            else
                r = (n + r - 1) % n;  // move backward circularly
        }

        return false;
    }
};

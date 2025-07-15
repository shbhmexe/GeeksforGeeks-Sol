class Solution {
  public:
    int find_first_position(vector<int>& arr, int target) {
        int l = 0, r = arr.size() - 1;
        int result = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == target) {
                result = mid;
                r = mid - 1;
            } else if (arr[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }

    int find_last_position(vector<int>& arr, int target) {
        int l = 0, r = arr.size() - 1;
        int result = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == target) {
                result = mid;
                l = mid + 1;
            } else if (arr[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }

    int countFreq(vector<int>& arr, int target) {
        int l = find_first_position(arr, target);
        int r = find_last_position(arr, target);

        if (l == -1 || r == -1) {
            return 0;  // target not found
        }

        return r - l + 1;
    }
};

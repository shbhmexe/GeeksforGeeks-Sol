class Solution {
  public:
    int find_first_position(vector<int>& arr, int x) {
        int l = 0, r = arr.size() - 1;
        int result = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == x) {
                result = mid;
                r = mid - 1; // search left side
            } else if (arr[mid] > x) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }

    int find_last_position(vector<int>& arr, int x) {
        int l = 0, r = arr.size() - 1;
        int result = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == x) {
                result = mid;
                l = mid + 1; // search right side
            } else if (arr[mid] > x) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }

    vector<int> firstAndLast(int x, vector<int>& arr) {
        int l = find_first_position(arr, x);
        int r = find_last_position(arr, x);

        if (l == -1) {
            return { -1 }; // if not found, return only one -1
        } else {
            return { l, r }; // return both indices
        }
    }
};

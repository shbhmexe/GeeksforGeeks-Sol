//Queston 20 june26
class Solution {
public:
    int binarySearchable(vector<int>& arr) {
        int count = 0;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            int target = arr[i];
            int l = 0;
            int r = n - 1;
            bool is_searchable = false;
            
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (arr[mid] == target) {
                    is_searchable = true;
                    break;
                }
                if (arr[mid] < target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            
            if (is_searchable) {
                count++;
            }
        }
        
        return count;
    }
};
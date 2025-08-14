//Question 348
class Solution {
public:
    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;
        int mid = left + (right - left) / 2;
        int count = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);

        // Count cross pairs
        int j = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && (long long)nums[i] > 2LL * nums[j])
                j++;
            count += (j - (mid + 1));
        }

        // Merge step
        vector<int> temp;
        int i = left; j = mid + 1;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }
        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= right) temp.push_back(nums[j++]);

        for (int i = left; i <= right; i++)
            nums[i] = temp[i - left];

        return count;
    }

    int countRevPairs(vector<int>& arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};

class Solution {
  public:
    static bool myFunction(int a, int b) {
        string s1 = to_string(a);
        string s2 = to_string(b);
        return (s1 + s2) > (s2 + s1);  // larger combination comes first
    }

    string findLargest(vector<int> &arr) {
        sort(arr.begin(), arr.end(), myFunction);

        // If the largest number is 0, the result is just "0"
        if (arr[0] == 0)
            return "0";

        string result = "";
        for (int i : arr)
            result += to_string(i);

        return result;
    }
};

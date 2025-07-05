#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> nextSmallerElements(vector<int>& arr, int n) {
        vector<int> v(n);
        stack<int> s;
        s.push(-1);

        for (int i = n - 1; i >= 0; i--) {
            while (s.top() != -1 && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            v[i] = s.top();
            s.push(i);
        }
        return v;
    }

    vector<int> prevSmallerElements(vector<int>& arr, int n) {
        vector<int> v(n);
        stack<int> s;
        s.push(-1);

        for (int i = 0; i < n; i++) {
            while (s.top() != -1 && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            v[i] = s.top();
            s.push(i);
        }
        return v;
    }

    int largestRectangleArea(vector<int>& heights, int n) {
        vector<int> next = nextSmallerElements(heights, n);
        vector<int> prev = prevSmallerElements(heights, n);

        int area = INT_MIN;

        for (int i = 0; i < n; i++) {
            int l = heights[i];
            if (next[i] == -1)
                next[i] = n;

            int b = next[i] - prev[i] - 1;
            int ans = l * b;
            area = max(area, ans);
        }
        return area;
    }

public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> heights(m, 0);
        int area = 0;

        for (int i = 0; i < n; i++) {
            // update heights array for current row
            for (int j = 0; j < m; j++) {
                if (mat[i][j] != 0)
                    heights[j] += mat[i][j];
                else
                    heights[j] = 0;
            }
            area = max(area, largestRectangleArea(heights, m));
        }

        return area;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> mat = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}
    };

    cout << "Max Area of Rectangle: " << obj.maxArea(mat) << endl;

    return 0;
}



// class Solution {
// private:
//     vector<int> nextSmallerElements(vector<int>& arr, int n) {
//         vector<int> v(n);
//         stack<int> s;
//         s.push(-1);

//         for (int i = n - 1; i >= 0; i--) {
//             while (s.top() != -1 && arr[s.top()] >= arr[i]) {
//                 s.pop();
//             }
//             v[i] = s.top();
//             s.push(i);
//         }
//         return v;
//     }

//     vector<int> prevSmallerElements(vector<int>& arr, int n) {
//         vector<int> v(n);
//         stack<int> s;
//         s.push(-1);

//         for (int i = 0; i < n; i++) {
//             while (s.top() != -1 && arr[s.top()] >= arr[i]) {
//                 s.pop();
//             }
//             v[i] = s.top();
//             s.push(i);
//         }
//         return v;
//     }

//     int largestRectangleArea(vector<int>& heights, int n) {
//         vector<int> next = nextSmallerElements(heights, n);
//         vector<int> prev = prevSmallerElements(heights, n);

//         int area = INT_MIN;

//         for (int i = 0; i < n; i++) {
//             int l = heights[i];
//             if (next[i] == -1)
//                 next[i] = n;

//             int b = next[i] - prev[i] - 1;
//             int ans = l * b;
//             area = max(area, ans);
//         }
//         return area;
//     }

// public:
//     int maxArea(vector<vector<int>>& mat) {
//         int n = mat.size();
//         int m = mat[0].size();

//         vector<int> heights(m, 0);
//         int area = 0;

//         for (int i = 0; i < n; i++) {
//             // update heights array for current row
//             for (int j = 0; j < m; j++) {
//                 if (mat[i][j] != 0)
//                     heights[j] += mat[i][j];
//                 else
//                     heights[j] = 0;
//             }
//             area = max(area, largestRectangleArea(heights, m));
//         }

//         return area;
//     }
// };
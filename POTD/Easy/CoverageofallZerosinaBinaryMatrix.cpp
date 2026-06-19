//Question 53
//Brute Force 
// class Solution {
// public:
//     int findCoverage(vector<vector<int>>& mat) {
//         int n = mat.size();
//         int m = mat[0].size();
//         int ans = 0;

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (mat[i][j] == 0) {
//                     for (int k = j - 1; k >= 0; k--) {
//                         if (mat[i][k] == 1) { 
//                             ans++; 
//                             break; 
//                         }
//                     }
//                     for (int k = j + 1; k < m; k++) {
//                         if (mat[i][k] == 1) { 
//                             ans++; 
//                             break; 
//                         }
//                     }
//                     for (int k = i - 1; k >= 0; k--) {
//                         if (mat[k][j] == 1) { 
//                             ans++; 
//                             break; 
//                         }
//                     }
//                     for (int k = i + 1; k < n; k++) {
//                         if (mat[k][j] == 1) { 
//                             ans++; 
//                             break; 
//                         }
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };

//Optimize
class Solution {
public:
    int findCoverage(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        
        vector<vector<int>> left(n, vector<int>(m, 0));
        vector<vector<int>> right(n, vector<int>(m, 0));
        vector<vector<int>> up(n, vector<int>(m, 0));
        vector<vector<int>> down(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; i++) {
            int seen = 0;
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) seen = 1;
                left[i][j] = seen;
            }
            seen = 0;
            for (int j = m - 1; j >= 0; j--) {
                if (mat[i][j] == 1) seen = 1;
                right[i][j] = seen;
            }
        }
        
        for (int j = 0; j < m; j++) {
            int seen = 0;
            for (int i = 0; i < n; i++) {
                if (mat[i][j] == 1) seen = 1;
                up[i][j] = seen;
            }
            seen = 0;
            for (int i = n - 1; i >= 0; i--) {
                if (mat[i][j] == 1) seen = 1;
                down[i][j] = seen;
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    if (j > 0 && left[i][j - 1]) ans++;
                    if (j < m - 1 && right[i][j + 1]) ans++;
                    if (i > 0 && up[i - 1][j]) ans++;
                    if (i < n - 1 && down[i + 1][j]) ans++;
                }
            }
        }
        
        return ans;
    }
};
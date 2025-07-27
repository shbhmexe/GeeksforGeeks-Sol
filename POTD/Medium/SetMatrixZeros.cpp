//Question 262

class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        bool isFirstRowZero = false, isFirstColZero = false;

        // Step 1: Check if first row has 0
        for (int j = 0; j < m; j++) {
            if (mat[0][j] == 0) {
                isFirstRowZero = true;
                break;
            }
        }

        // Step 2: Check if first column has 0
        for (int i = 0; i < n; i++) {
            if (mat[i][0] == 0) {
                isFirstColZero = true;
                break;
            }
        }

        // Step 3: Mark rows and columns
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (mat[i][j] == 0) {
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }

        // Step 4: Apply markings
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (mat[i][0] == 0 || mat[0][j] == 0) {
                    mat[i][j] = 0;
                }
            }
        }

        // Step 5: Zero out first row
        if (isFirstRowZero) {
            for (int j = 0; j < m; j++) {
                mat[0][j] = 0;
            }
        }

        // Step 6: Zero out first column
        if (isFirstColZero) {
            for (int i = 0; i < n; i++) {
                mat[i][0] = 0;
            }
        }
    }
};

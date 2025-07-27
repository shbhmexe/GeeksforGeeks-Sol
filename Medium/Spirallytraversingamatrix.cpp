//Question 237
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        vector<int> ans;
        int row = mat.size();
        int col = mat[0].size();

        int startingRow = 0;
        int startingCol = 0;
        int endingRow = row - 1;
        int endingCol = col - 1;

        int count = 0;
        int total = row * col;

        while (count < total) {
            // 1. Print top row
            for (int i = startingCol; i <= endingCol && count < total; i++) {
                ans.push_back(mat[startingRow][i]);
                count++;
            }
            startingRow++;

            // 2. Print right column
            for (int i = startingRow; i <= endingRow && count < total; i++) {
                ans.push_back(mat[i][endingCol]);
                count++;
            }
            endingCol--;

            // 3. Print bottom row
            for (int i = endingCol; i >= startingCol && count < total; i--) {
                ans.push_back(mat[endingRow][i]);
                count++;
            }
            endingRow--;

            // 4. Print left column
            for (int i = endingRow; i >= startingRow && count < total; i--) {
                ans.push_back(mat[i][startingCol]);
                count++;
            }
            startingCol++;
        }

        return ans;
    }
};

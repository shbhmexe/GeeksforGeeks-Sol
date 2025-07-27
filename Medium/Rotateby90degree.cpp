// Question 235
// User function template for C++

/* matrix : given input matrix, you are require
 to change it in place without using extra space */
void rotate(vector<vector<int> >& mat) {
     int n = mat.size();
        
        // step 1 : transpose of matrix
        for (int i=0; i<n-1; i++) {
            for (int j=i+1; j<n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }

        // step 2 : reverse each row
        for (int i=0; i<n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
}

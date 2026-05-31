//Queston 782
class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& vis, int n, int m) {
        vis[r][c] = 1;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        for(int i = 0; i < 4; i++) {
            int nrow = r + delRow[i];
            int ncol = c + delCol[i];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, grid, vis, n, m);
            }
        }
    }
    
    int cntOnes(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int j = 0; j < m; j++) {
            if(!vis[0][j] && grid[0][j] == 1) {
                dfs(0, j, grid, vis, n, m);
            }
            if(!vis[n-1][j] && grid[n-1][j] == 1) {
                dfs(n-1, j, grid, vis, n, m);
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(!vis[i][0] && grid[i][0] == 1) {
                dfs(i, 0, grid, vis, n, m);
            }
            if(!vis[i][m-1] && grid[i][m-1] == 1) {
                dfs(i, m-1, grid, vis, n, m);
            }
        }
        
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    count++;
                }
            }
        }
        
        return count;
    }
};
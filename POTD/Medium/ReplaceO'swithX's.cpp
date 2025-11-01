//Question 530
class Solution {
public:
    void fill(vector<vector<char>>& grid) {
        int shbhm = grid.size();
        if (shbhm == 0) {
            return;
        }
        int exe = grid[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < shbhm; i++) {
            if (grid[i][0] == 'O') {
                grid[i][0] = '$';
                q.push({i, 0});
            }
            if (grid[i][exe - 1] == 'O') {
                grid[i][exe - 1] = '$';
                q.push({i, exe - 1});
            }
        }

        for (int j = 0; j < exe; j++) {
            if (grid[0][j] == 'O') {
                grid[0][j] = '$';
                q.push({0, j});
            }
            if (grid[shbhm - 1][j] == 'O') {
                grid[shbhm - 1][j] = '$';
                q.push({shbhm - 1, j});
            }
        }

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < shbhm && nc >= 0 && nc < exe && grid[nr][nc] == 'O') {
                    grid[nr][nc] = '$';
                    q.push({nr, nc});
                }
            }
        }

        for (int i = 0; i < shbhm; i++) {
            for (int j = 0; j < exe; j++) {
                if (grid[i][j] == 'O') {
                    grid[i][j] = 'X';
                } else if (grid[i][j] == '$') {
                    grid[i][j] = 'O';
                }
            }
        }
    }
};
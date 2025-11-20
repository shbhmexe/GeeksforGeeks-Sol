//Question 574
class Solution {
    
public:
    int minCost(string s, string t, vector<vector<char>>& transform, vector<int>& cost) {
        const int INF = 1e9;
        vector<vector<int>> exe(26, vector<int>(26, INF));

        for (int i = 0; i < 26; ++i) exe[i][i] = 0;

        for (size_t i = 0; i < transform.size(); ++i) {
            int u = transform[i][0] - 'a';
            int v = transform[i][1] - 'a';
            exe[u][v] = min(exe[u][v], cost[i]);
        }

        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (exe[i][k] != INF && exe[k][j] != INF) {
                        exe[i][j] = min(exe[i][j], exe[i][k] + exe[k][j]);
                    }
                }
            }
        }

        long long shbhm = 0;
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            if (s[i] == t[i]) continue;

            int u = s[i] - 'a';
            int v = t[i] - 'a';
            int min_op = INF;

            for (int k = 0; k < 26; ++k) {
                if (exe[u][k] != INF && exe[v][k] != INF) {
                    min_op = min(min_op, exe[u][k] + exe[v][k]);
                }
            }

            if (min_op == INF) return -1;
            shbhm += min_op;
        }

        return (int)shbhm;
    }
};
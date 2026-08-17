class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0)
                    q.push({r, c});
            }
        }

        int dist = 0;
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                        continue;

                    if (grid[nr][nc] != 2147483647)
                        continue;

                    grid[nr][nc] = dist + 1;
                    q.push({nr, nc});
                }
            }

            dist++;
        }
    }
};
class Solution {
    int m, n;
    vector<vector<int>> h;
    vector<vector<bool>> pacific, atlantic;

    void dfs(int r, int c, vector<vector<bool>>& ocean) {
        ocean[r][c] = true;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                continue;

            if (ocean[nr][nc])
                continue;

            if (h[nr][nc] < h[r][c])
                continue;

            dfs(nr, nc, ocean);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        h = heights;
        m = h.size();
        n = h[0].size();

        pacific.assign(m, vector<bool>(n, false));
        atlantic.assign(m, vector<bool>(n, false));

        for (int r = 0; r < m; r++) {
            dfs(r, 0, pacific);
            dfs(r, n - 1, atlantic);
        }

        for (int c = 0; c < n; c++) {
            dfs(0, c, pacific);
            dfs(m - 1, c, atlantic);
        }

        vector<vector<int>> ans;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (pacific[r][c] && atlantic[r][c])
                    ans.push_back({r, c});
            }
        }

        return ans;
    }
};
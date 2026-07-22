class Solution {
    //vvimp
public:
    int m, n;
    vector<vector<int>> dp;
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    int dfs(int i, int j, vector<vector<int>>& matrix) {
        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 1;

        for (auto [dx, dy] : dir) {
            int x = i + dx;
            int y = j + dy;

            if (x >= 0 && x < m &&
                y >= 0 && y < n &&
                matrix[x][y] > matrix[i][j]) {

                ans = max(ans,
                          1 + dfs(x, y, matrix));
            }
        }

        return dp[i][j] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        m = matrix.size();
        n = matrix[0].size();

        dp.assign(m, vector<int>(n, -1));

        int ans = 0;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans = max(ans, dfs(i, j, matrix));

        return ans;
    }
};
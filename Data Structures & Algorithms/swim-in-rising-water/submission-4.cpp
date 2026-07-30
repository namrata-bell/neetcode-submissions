class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>> > pq;

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int cost = curr.first;
            int r = curr.second.first;
            int c = curr.second.second;

            // Skip stale entries
            if (cost > dist[r][c]) continue;

            if (r == n - 1 && c == n - 1)
                return cost;

            for (int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                    continue;

                int newCost = max(cost, grid[nr][nc]);

                if (newCost < dist[nr][nc]) {
                    dist[nr][nc] = newCost;
                    pq.push({newCost, {nr, nc}});
                }
            }
        }

        return -1;
    }
};
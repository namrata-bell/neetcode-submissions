class Solution {
    unordered_map<string, vector<string>> adj;
    vector<string> path;

    void dfs(string airport) {
        while (!adj[airport].empty()) {
            string next = adj[airport].back();
            adj[airport].pop_back();
            dfs(next);
        }

        path.push_back(airport);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& t : tickets)
            adj[t[0]].push_back(t[1]);

        for (auto& [from, dest] : adj)
            sort(dest.rbegin(), dest.rend());

        dfs("JFK");

        reverse(path.begin(), path.end());

        return path;
    }
};
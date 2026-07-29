class Solution {
public:

    bool dfs(int node, int parent,
             vector<vector<int>>& adj,
             vector<bool>& vis){

        vis[node] = true;

        for(int nei : adj[node]){

            if(!vis[nei]){
                if(dfs(nei, node, adj, vis))
                    return true;
            }
            else if(nei != parent){
                return true;
            }
        }

        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        // Tree must have exactly n-1 edges
        if(edges.size() != n-1)
            return false;

        vector<vector<int>> adj(n);

        for(auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> vis(n, false);

        // Cycle check
        if(dfs(0, -1, adj, vis))
            return false;

        // Connectivity check
        for(bool x : vis){
            if(!x)
                return false;
        }

        return true;
    }
};
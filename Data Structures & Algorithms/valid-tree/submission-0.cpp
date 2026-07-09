class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[node] = true;

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                if (!dfs(nei, node, adj, vis))
                    return false;
            }
            else if (nei != parent) {
                // Cycle found
                return false;
            }
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        // A tree must have exactly n-1 edges
        if (edges.size() != n - 1)
            return false;

        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);

        if (!dfs(0, -1, adj, vis))
            return false;

        // Check connectivity
        for (bool x : vis) {
            if (!x)
                return false;
        }

        return true;
    }
};
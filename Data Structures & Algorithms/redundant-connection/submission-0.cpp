class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool Union(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return false;

        if (rank[px] < rank[py])
            parent[px] = py;
        else if (rank[px] > rank[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }

        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        for (auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];

            if (!Union(u, v))
                return edge;
        }

        return {};
    }
};
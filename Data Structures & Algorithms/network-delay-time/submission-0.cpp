class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n + 1);

        // Build graph
        for (auto &edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
        }

        // Distance array
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        // Min Heap -> {distance, node}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        pq.push({0, k});

        while (!pq.empty()) {

            auto [d, node] = pq.top();
            pq.pop();

            // Ignore outdated entries
            if (d > dist[node])
                continue;

            for (auto &it : adj[node]) {

                int next = it.first;
                int wt = it.second;

                if (dist[node] + wt < dist[next]) {

                    dist[next] = dist[node] + wt;
                    pq.push({dist[next], next});
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {

            if (dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
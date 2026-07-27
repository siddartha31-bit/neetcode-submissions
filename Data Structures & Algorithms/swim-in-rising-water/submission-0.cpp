class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        vector<vector<bool>> vis(n, vector<bool>(n, false));

        pq.push({grid[0][0], 0, 0});

        int dir[5] = {-1, 0, 1, 0, -1};

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int time = cur[0];
            int x = cur[1];
            int y = cur[2];

            if (vis[x][y])
                continue;

            vis[x][y] = true;

            if (x == n - 1 && y == n - 1)
                return time;

            for (int k = 0; k < 4; k++) {
                int nx = x + dir[k];
                int ny = y + dir[k + 1];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny]) {
                    pq.push({max(time, grid[nx][ny]), nx, ny});
                }
            }
        }

        return -1;
    }
};
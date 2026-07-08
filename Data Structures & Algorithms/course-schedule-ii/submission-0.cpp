class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        // Adjacency list
        vector<vector<int>> adj(numCourses);

        // Indegree array
        vector<int> indegree(numCourses, 0);

        // Build graph
        for (auto &pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];

            adj[prereq].push_back(course);
            indegree[course]++;
        }

        // Queue for courses with no prerequisites
        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;

        // Kahn's Algorithm
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;

                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // If cycle exists
        if (ans.size() != numCourses)
            return {};

        return ans;
    }
};

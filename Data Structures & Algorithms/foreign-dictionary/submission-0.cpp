class Solution {
public:
    string foreignDictionary(vector<string>& words) {

        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> indegree;

        // Add every character
        for (auto &word : words) {
            for (char c : word) {
                indegree[c] = 0;
            }
        }

        // Build graph
        for (int i = 0; i < words.size() - 1; i++) {

            string w1 = words[i];
            string w2 = words[i + 1];

            int len = min(w1.size(), w2.size());

            // Invalid case
            if (w1.size() > w2.size() &&
                w1.substr(0, len) == w2.substr(0, len))
                return "";

            for (int j = 0; j < len; j++) {

                if (w1[j] != w2[j]) {

                    if (!graph[w1[j]].count(w2[j])) {
                        graph[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    break;
                }
            }
        }

        queue<char> q;

        for (auto &it : indegree) {
            if (it.second == 0)
                q.push(it.first);
        }

        string ans;

        while (!q.empty()) {

            char node = q.front();
            q.pop();

            ans += node;

            for (char neigh : graph[node]) {
                indegree[neigh]--;

                if (indegree[neigh] == 0)
                    q.push(neigh);
            }
        }

        if (ans.size() != indegree.size())
            return "";

        return ans;
    }
};
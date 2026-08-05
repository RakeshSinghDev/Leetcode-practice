class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> vis;

    void dfs(int node) {
        vis[node] = true;

        for (int next : graph[node]) {
            if (!vis[next])
                dfs(next);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        graph.resize(n);
        vis.assign(n, false);

        // Build graph
        for (auto &e : invocations) {
            graph[e[0]].push_back(e[1]);
        }

        // Mark suspicious methods
        dfs(k);

        // Check if any safe method calls a suspicious method
        for (auto &e : invocations) {
            int u = e[0];
            int v = e[1];

            if (!vis[u] && vis[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        // Return only safe methods
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!vis[i])
                ans.push_back(i);
        }

        return ans;
    }
};
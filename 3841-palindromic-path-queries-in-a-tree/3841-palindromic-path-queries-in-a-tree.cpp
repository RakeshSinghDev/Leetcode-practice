
class Solution {
    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int n) : n(n), bit(n + 2, 0) {}

        void add(int idx, int val) {
            for (; idx <= n; idx += idx & -idx) {
                bit[idx] ^= val;
            }
        }

        void rangeXor(int l, int r, int val) {
            add(l, val);
            add(r + 1, val);
        }

        
        int query(int idx) {
            int res = 0;
            for (; idx > 0; idx -= idx & -idx) {
                res ^= bit[idx];
            }
            return res;
        }
    };

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) ++LOG;

        vector<vector<int>> up(LOG, vector<int>(n, 0));
        vector<int> depth(n, 0), tin(n), tout(n);
        vector<int> pref(n, 0);

        int timer = 0;

      
        stack<array<int, 3>> st;
        st.push({0, 0, 0});

        while (!st.empty()) {
            auto cur = st.top();
            st.pop();

            int u = cur[0];
            int p = cur[1];
            int state = cur[2];

            if (state == 0) {
                tin[u] = ++timer;
                up[0][u] = p;

                if (u == 0) {
                    pref[u] = 1 << (s[u] - 'a');
                } else {
                    pref[u] =
                        pref[p] ^ (1 << (s[u] - 'a'));
                }

                for (int j = 1; j < LOG; ++j) {
                    up[j][u] = up[j - 1][up[j - 1][u]];
                }

                st.push({u, p, 1});

                for (int i = (int)adj[u].size() - 1;
                     i >= 0; --i) {
                    int v = adj[u][i];

                    if (v == p) continue;

                    depth[v] = depth[u] + 1;
                    st.push({v, u, 0});
                }
            } else {
                tout[u] = timer;
            }
        }

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);

            int diff = depth[u] - depth[v];

            for (int j = 0; j < LOG; ++j) {
                if (diff & (1 << j)) {
                    u = up[j][u];
                }
            }

            if (u == v) return u;

            for (int j = LOG - 1; j >= 0; --j) {
                if (up[j][u] != up[j][v]) {
                    u = up[j][u];
                    v = up[j][v];
                }
            }

            return up[0][u];
        };

        Fenwick fw(n);

        auto getPrefix = [&](int u) {
            return pref[u] ^ fw.query(tin[u]);
        };

        vector<bool> ans;

        for (const string& q : queries) {
            stringstream ss(q);
            string type;
            int u, v;

            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int oldMask = 1 << (s[u] - 'a');
                int newMask = 1 << (c - 'a');
                int delta = oldMask ^ newMask;

                if (delta != 0) {
                    
                    fw.rangeXor(tin[u], tout[u], delta);
                    s[u] = c;
                }
            } else {
                ss >> v;

                int w = lca(u, v);

                int mask = getPrefix(u)
                         ^ getPrefix(v)
                         ^ (1 << (s[w] - 'a'));

                ans.push_back(
                    (mask & (mask - 1)) == 0
                );
            }
        }

        return ans;
    }
};

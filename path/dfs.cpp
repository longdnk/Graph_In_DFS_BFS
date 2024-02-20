#include <bits/stdc++.h>

using namespace std;

const int maxN = 1009;
int n, m, s, t, parent[maxN];
vector<int> a[maxN];
bool check[maxN];

void dfs(int u) {
    check[u] = true;
    if (u == t) {
        vector<int> path;
        while (t) {
            path.emplace_back(t);
            t = parent[t];
        }
        cout << path.size() - 1 << '\n';
        for (int i = path.size() - 1; i >= 0; --i) {
            cout << path[i] << ' ';
        }
    }
    for (int v : a[u]) {
        if (!check[v]) {
            parent[v] = u;
            dfs(v);
        }
    }
}

void findPath() {
    dfs(s);
    if (!check[t]) {
        cout << -1 << '\n';
        exit(0);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> s >> t;
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        a[u].emplace_back(v);
        a[v].emplace_back(u);
    }
    findPath();
}
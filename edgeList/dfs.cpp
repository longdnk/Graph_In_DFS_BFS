#include <bits/stdc++.h>

using namespace std;

const int maxN = 1009;
int n, m, linked[maxN], head[maxN];
bool check[maxN];

struct edge {
    int u, v;
} e[maxN];

void dfs(int u) {
    check[u] = true;
    cout << u << ' ';
    vector<int> adj;
    for (int i = head[u]; i; i = linked[i]) {
        adj.emplace_back(e[i].v);
    }
    sort(adj.begin(), adj.end());
    for (int v : adj) {
        if (!check[v]) {
            dfs(v);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        e[i] = {u, v};
        e[i + m] = {u, v};
    }
    for (int i = 1; i <= 2 * m; ++i) {
        linked[i] = head[e[i].u];
        head[e[i].u] = i;
    }
    dfs(1);
}
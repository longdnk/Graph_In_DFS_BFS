#include <bits/stdc++.h>

using namespace std;

const int maxN = 1009;
int n, m, s, t, parent[maxN];
vector<int> a[maxN];
bool check[maxN];

void bfs(int x) {
    queue<int> q;
    check[x] = true;
    q.push(x);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : a[u]) {
            if (!check[v]) {
                parent[v] = u;
                check[v] = true;
                q.push(v);
            }
        }
    }
}

void findPath() {
    bfs(s);
    if (!check[s]) {
        cout << -1 << '\n';
        return;
    }
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
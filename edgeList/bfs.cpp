#include <bits/stdc++.h>

using namespace std;

const int maxN = 1009;
int n, m, linked[maxN], head[maxN];
bool check[maxN];

struct edge {
    int u, v;
} e[maxN];

void bfs(int x) {
    queue<int> q;
    check[x] = true;
    q.push(x);
    while (!q.empty()) {
        int u = q.front();
        cout << u << ' ';
        q.pop();
        vector<int> adj;
        for (int i = head[u]; i; i = linked[i]) {
            adj.emplace_back(e[i].v);
        }
        sort(adj.begin(), adj.end());
        for (int v : adj) {
            if (!check[v]) {
                check[v] = true;
                q.push(v);
            }
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
    bfs(1);
}
#include <bits/stdc++.h>

using namespace std;

const int maxN = 1009;
int n, m;
vector<int> a[maxN];
bool check[maxN];

void bfs(int x) {
    queue<int> q;
    check[x] = true;
    q.push(x);
    while (!q.empty()) {
        int u = q.front();
        cout << u << ' ';
        q.pop();
        for (int v : a[u]) {
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
        a[u].emplace_back(v);
        a[v].emplace_back(u);
    }
    bfs(1);
}
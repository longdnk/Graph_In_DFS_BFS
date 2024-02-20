#include <bits/stdc++.h>

using namespace std;

const int maxN = 1009;
int n, m, ans;
vector<int> a[maxN];
bool check[maxN];

void dfs(int u = 1) {
    check[u] = true;
    ++ans;
    for (int v : a[u]) {
        if (!check[v]) {
            dfs(v);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        a[u].emplace_back(v);
        a[v].emplace_back(u);
    }
    dfs();
    cout << n - ans << '\n';
    for (int i = 1; i <= n; ++i) {
        if (!check[i]) {
            cout << i << ' ';
        }
    }
}
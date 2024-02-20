#include "bits/stdc++.h"
using namespace std;

const int maxN = 1e5 + 9;
bool check[maxN];
int n, m, ans;
vector<vector<int>> a, res;

void dfs(int u) {
    check[u] = true;
    auto it = lower_bound(res[ans].begin(), res[ans].end(), u);
    res[ans].insert(it, u);
    for (int x : a[u]) {
        if (!check[x]) {
            dfs(x);
        }
    }
}

void findComponent() {
    for (int i = 1; i <= n; ++i) {
        if (!check[i]) {
            ++ans;
            dfs(i);
        }
    }
    cout << ans << '\n';
    for (int i = 1; i <= ans; ++i) {
        cout << res[i].size() << ' ';
        for (auto x : res[i]) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    a = res = vector<vector<int>>(n + 1);
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        a[u].emplace_back(v);
        a[v].emplace_back(u);
    }
    findComponent();
}
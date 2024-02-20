#include <bits/stdc++.h>

using namespace std;

const int maxN = 1009;
int n, m, a[maxN][maxN];
bool check[maxN];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        a[u][v] = a[v][u] = 1;
    }
}
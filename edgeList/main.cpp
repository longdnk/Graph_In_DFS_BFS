#include <bits/stdc++.h>

using namespace std;

const int maxN = 1009;
int n, m, linked[maxN], head[maxN];
bool check[maxN];

struct edge {
    int u, v;
} e[maxN];

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
}
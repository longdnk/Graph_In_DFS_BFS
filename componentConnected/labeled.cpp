#include "bits/stdc++.h"
using namespace std;
const int maxn = 1e6 + 9;
int n, m, a[1009][1009], u, v, vertex[maxn];

inline void findCompcon(int n, int label[], int i) {
    for (int j = 0; j < n; ++j)
        if (a[i][j] != 0 && label[j] != label[i]) {
            label[j] = label[i];
            findCompcon(n, label, j);
        }
}

inline void checkCompcon() {
    int label[1009], i, SothanhphanLT = 0;
    fill(label, label + n, 0);
    for (i = 0; i < n; ++i)
        if (label[i] == 0) {
            ++SothanhphanLT;
            label[i] = SothanhphanLT;
            findCompcon(n, label, i);
        }
    int z = 0, x = 0;
    for (i = 1; i <= SothanhphanLT; ++i) {
        int cnt = 0, f = -1;
        for (int j = 0; j < n; ++j) {
            if (label[j] == i)
                ++cnt;
            f = max(cnt, f);
        }
        vertex[z] = f;
        ++z;
    }
    cout << SothanhphanLT << '\n';
    for (i = 1; i <= SothanhphanLT; ++i) {
        cout << vertex[x] << ' ';
        for (int j = 0; j < n; ++j)
            if (label[j] == i)
                cout << j + 1 << ' ';
        ++x;
        cout << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        --u, --v, a[u][v] = 1, a[v][u] = 1;
    }
    checkCompcon();
}
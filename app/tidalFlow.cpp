#include <bits/stdc++.h>
using namespace std;
#define nmax 1201
#define mmax 120001
#define oo 2147483647
struct edge {
    int u, v, c, f;
} e[2 * mmax];
int n, m, s, t, fValue = 0, head[nmax], link[2 * mmax];
int h[nmax], l[nmax], p[2 * mmax], d[nmax], le[2 * mmax], lm;
void enter() {
    cin >> n >> m >> s >> t;
    for (int u, v, c, i = 1; i <= m; i++) {
        cin >> u >> v >> c;
        e[i] = {u, v, c, 0};
        e[i + m] = {v, u, 0, 0};
    }
    memset(head, 0, sizeof head);
    for (int i = 1; i <= 2 * m; i++) {
        link[i] = head[e[i].u];
        head[e[i].u] = i;
    }
}

bool BFS() {
    queue<int> q;
    q.push(s);
    memset(d, -1, sizeof d);
    d[s] = lm = 0;
    while (q.size()) {
        int u = q.front();
        q.pop();
        if (u == t)
            continue;
        for (int i = head[u]; i; i = link[i]) {
            int v = e[i].v, c = e[i].c, f = e[i].f;
            if (c <= f)
                continue;
            if (d[v] >= 0) {
                if (d[v] == d[u] + 1)
                    le[++lm] = i;
            }
            else {
                d[v] = d[u] + 1;
                q.push(v);
                le[++lm] = i;
            }
        }
    }
    return d[t] >= 0;
}

int TideCycle() {
    if (!BFS())
        return 0;
    memset(h, 0, sizeof h);
    h[s] = oo;
    for (int j = 1; j <= lm; j++) {
        int i = le[j];
        p[i] = min(e[i].c - e[i].f, h[e[i].u]);
        h[e[i].v] += p[i];
    }
    if (!h[t])
        return 0;
    memset(l, 0, sizeof l);
    l[t] = h[t];
    for (int j = lm; j >= 1; j--) {
        int i = le[j];
        p[i] = min(p[i], min(h[e[i].u] - l[e[i].u], l[e[i].v]));
        l[e[i].v] -= p[i];
        l[e[i].u] += p[i];
    }
    memset(h, 0, sizeof h);
    h[s] = l[s];
    for (int j = 1; j <= lm; j++) {
        int i = le[j];
        p[i] = min(p[i], h[e[i].u]);
        h[e[i].u] -= p[i];
        h[e[i].v] += p[i];
        e[i].f += p[i];
        e[i > m ? i - m : i + m].f -= p[i];
    }
    return h[t];
}

void TidalFlow() {
    while (TideCycle())
        fValue += h[t];
    cout << fValue << '\n';
    for (int i = 1; i <= m; ++i)
        if (e[i].f > 0)
            cout << e[i].u << ' ' << e[i].v << ' ' << e[i].f << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    enter();
    TidalFlow();
}
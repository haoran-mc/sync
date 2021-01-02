#include <stdio.h>
#include <stdlib.h>
const int maxn = 105;
const int mod  = 1e5;
int ranks[maxn] ;
int parent[maxn];
int g[maxn][maxn];

void init (int n) {
    for(int i = 0; i < n; ++i) {
        ranks[i]  = 1;
        parent[i] = i;
        g[i][i]   = 0;
    }
}

int find_root(int x) {
    if (x != parent[x])
        parent[x] = find_root(parent[x]);
    return parent[x];
}

void union_vert(int x, int y) {
    int x_root = find_root(x);
    int y_root = find_root(y);
    if (x_root == y_root)
        return;
    if (ranks[x_root] >= ranks[y_root]) {
        ranks[x_root] += ranks[y_root];
        parent[y_root] = x_root;
    }
    else {
        ranks[y_root] += ranks[y_root];
        parent[x_root] = y_root;
    }
}

template<typename T>
T binPow(T base, T expo) {
    T res = 1;
    while (expo != 0) {
        if (expo & 1)
            res = (1LL * res * base) % mod;
        base = (1LL * base * base) % mod;
        expo >>= 1;
    }
    return res;
}

int main() {
    int n, m;
    int x, y;
    while (scanf("%d %d", &n, &m) != EOF) {
        init(n);
        for(int i = 0; i < m; ++i) {
            scanf("%d %d", &x, &y);
            int x_root = find_root(x);
            int y_root = find_root(y);
            if (x_root == y_root)
                continue;
            int dist = binPow(2, i);
            for(int j = 0; j < n; ++j) {
                if (x_root != find_root(j))
                    continue;
                for (int k = 0; k < n; ++k) {
                    if (y_root != find_root(k))
                        continue;
                    g[j][k] = g[k][j] = (g[j][x]+dist+g[y][k]) % 100000;
                }
            }
            union_vert(x, y);
        }
        x = find_root(0);
        for(int i = 1; i < n; ++i)
            find_root(i) != x ? printf("-1\n") : printf("%d\n", g[0][i]);
    }
    return 0;
}

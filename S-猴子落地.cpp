#include <cstdio>
#include <algorithm>
const int N  =  2e5 + 5;
const int M  =  4e5 + 5;
const int inf = 0x3f3f3f3f;
using namespace std;
int fa[N];
int monk[N][3];
int g[N][3];
int res[N];
int cast[2*N];
int elec[2*N];

int find_root(int x) {
    int t = fa[x];
    if (fa[x] !=  x)
        fa[x] = find_root(fa[x]);
    res[x] = min(res[x], res[t]);
    return fa[x];
}

void union_vert(int x, int y, int z) {
    int fx = find_root(x), fy = find_root(y);
    if (fx !=  fy) {
        if (fx == 1)
            swap(fx, fy);
        fa[fx] = fy;
        res[fx] = z;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &monk[i][1], &monk[i][2]);
        g[i][1] = monk[i][1];
        g[i][2] = monk[i][2];
        fa[i] = i, res[i] = inf;
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &cast[i], &elec[i]);
        monk[cast[i]][elec[i]] = -1;
    }
    for (int i = 1; i <= n; i++) {
        if (monk[i][1] !=  -1)
            union_vert(i, monk[i][1], inf);
        if (monk[i][2] !=  -1)
            union_vert(i, monk[i][2], inf);
    }
    for (int i = m; i >= 1; i--) {
        int x = cast[i];
        int y = g[x][elec[i]];
        if (y == -1)
            continue;
        union_vert(x, y, i-1);
    }
    for (int i = 1; i <= n; i++) {
        find_root(i);
        res[i] != inf ? printf("%d\n", res[i]) : printf("-1\n");
    }
    return 0;
}

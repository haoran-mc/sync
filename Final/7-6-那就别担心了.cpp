#include<stdio.h>
const int maxn = 505;
bool used[maxn];
bool g[maxn][maxn];
int n, m;
int orin;
int goal;
int way[maxn];
bool flag;

int DFS(int vert) {
    used[vert] = true;
    if (way[vert])
        return way[vert];
    bool runby = false;
    for (int i = 1; i <= n; ++i)
        if (g[vert][i]) {
            way[vert] += DFS(i);
            runby = true;
        }
    if (!runby)
        flag = true;
    return way[vert];
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int ver1, ver2;
        scanf("%d %d", &ver1, &ver2);
        g[ver1][ver2] = true;
    }
    scanf("%d %d", &orin, &goal);
    way[goal] = 1;
    int res = DFS(orin);
    printf("%d ", res);
    flag ? printf("No\n") : printf("Yes\n");
    return 0;
}

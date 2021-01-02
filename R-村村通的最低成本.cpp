#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 105;
const int inf = 0x3f3f3f3f;
int n;
int g[maxn][maxn];
int dist[maxn];

void prime() {
    memset(dist, 0x3f, sizeof(dist));
    int res  = 0;
    int vert = 1;
    for (int i = 1; i < n; ++i) {
        dist[vert] = -1;
        int minedge = inf;
        int minvert;
        for (int j = 1; j <= n; ++j) {
            if (j != vert&& dist[j] >= 0) {
                if (g[vert][j] >= 0)
                    dist[j] = min(dist[j], g[vert][j]);
                if (dist[j] < minedge) {
                    minedge = dist[j];
                    minvert = j;
                }
            }
        }
        res += minedge;
        vert = minvert;
    }
    printf("%d", res);
}

int main() {
    scanf("%d", &n) ;
    memset(g, 0, sizeof(g));
    for (int i = 0; i < n * (n-1) / 2; ++i) {
        int ver1, ver2, edge;
        int flag;
        scanf("%d %d %d %d", &ver1, &ver2, &edge, &flag);
        if (flag) {
            g[ver1][ver2] = 0;
            g[ver2][ver1] = 0;
        }
        else {
            g[ver2][ver1] = edge;
            g[ver1][ver2] = edge;
        }
    }
    prime();
    return 0;
}

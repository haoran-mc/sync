#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 505;
struct Ruler {
    int edge;
    int pay;
};
int n, m;
int source;
int target;
Ruler g[maxn][maxn];
bool used[maxn];
Ruler dist[maxn];

void dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    memset(used, 0, sizeof(used));
    dist[source].edge = 0;
    dist[source].pay  = 0;
    for (int i = 0; i < n; ++i) {
        int vert = -1;
        for (int j = 0; j < n; ++j)
            if (used[j] == false && (vert == -1 || dist[j].edge < dist[vert].edge))
                vert = j;
        used[vert] = true;
        for (int j = 0; j < n; ++j) {
            if (dist[j].edge == dist[vert].edge + g[vert][j].edge) {
                if (dist[j].pay > dist[vert].pay + g[vert][j].pay)
                    dist[j].pay = dist[vert].pay + g[vert][j].pay;
            }
            else if (dist[j].edge > dist[vert].edge + g[vert][j].edge) {
                dist[j].edge = dist[vert].edge + g[vert][j].edge;
                dist[j].pay = dist[vert].pay + g[vert][j].pay;
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    scanf("%d %d", &source, &target);
    memset(g, 0x3f, sizeof(g));
    for (int i = 0; i < m; ++i) {
        int ver1;
        int ver2;
        Ruler rule;
        scanf("%d %d", &ver1, &ver2);
        scanf("%d %d", &rule.edge, &rule.pay);
        g[ver1][ver2] = rule;
        g[ver2][ver1] = rule;
    }
    dijkstra();
    printf("%d %d\n", dist[target].edge, dist[target].pay);
    return 0;
}

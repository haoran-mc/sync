#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 5e4 + 5;
const int maxm = 5e4 + 5;
const int inf  = 0x3f3f3f3f;

struct Edge {
    int x;
    int y;
    int z;
    Edge() {}
    Edge(int _x, int _y, int _z): x(_x), y(_y), z(_z) {}
};

int tot;
int head[maxn];
int nxet[maxm];
Edge edge[maxm];
int dist[maxn];
bool inq[maxn];


void add(int x, int y, int z) {
    edge[tot] = Edge(x, y, z);
    nxet[tot] = head[x];
    head[x] = tot++;
}

int spfa(int n) {
    memset(inq, 0, sizeof(inq));
    for (int i = 0; i < n; ++i)
        dist[i] = i == 0 ? 0 : inf;
    queue <int>  Q;
    Q.push(0);
    while (!Q.empty()) {
        int u = Q.front();  Q.pop();
        inq[u] = false;
        for (int i = head[u]; i; i = nxet[i]) {
            Edge &e = edge[i];
            if (dist[e.y] > dist[u]+e.z) {
                dist[e.y] = dist[u]+e.z;
                if (!inq[e.y]) {
                    inq[e.y] = true;
                    Q.push(e.y);
                }
            }
        }
    }
    return dist[n-1]-dist[3];
}

int main() {
    int n;
    scanf("%d", &n);
    int cnt = -1;
    while (n--) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        x += 4;
        y += 4;
        cnt = max(cnt, y);
        add(y, x-1, -z);
    }
    for (int i = 4; i <= cnt; ++i) {
        add(i, i-1, 0);
        add(i-1, i, 1);
        add(0,   i, 0);
    }
    add(0, 3, 0);
    printf("%d", spfa(cnt + 1));
    return 0;
}

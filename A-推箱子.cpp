#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 22;
char coord[maxn][maxn];
int dirx[4] = {-1, 1, 0, 0};
int diry[4] = {0, 0, -1, 1};
int n;
int m;
struct chess{
    int x;
    int y;
};
chess peo; /*玩家的起始位置*/
chess bin; /*箱子的起始位置*/
chess aim; /*目标点起始位置*/
bool vis[maxn][maxn][maxn][maxn];
struct Pos {
    int peox;
    int peoy;
    int binx;
    int biny;
    int step;
};

void BFS() {
    queue<Pos> quu;
    Pos now;
    Pos nxt;
    now.peox = peo.x;
    now.peoy = peo.y;
    now.binx = bin.x;
    now.biny = bin.y;
    now.step = 0;
    vis[peo.x][peo.y][bin.x][bin.y] = true;
    quu.push(now);
    while(!quu.empty()) {
        now = quu.front();
        if (now.binx == aim.x && now.biny == aim.y) {
            printf("%d", now.step);
            return;
        }
        quu.pop();
        for(int i = 0; i < 4; ++i) {
            chess seek_peo;
            seek_peo.x = now.peox + dirx[i];
            seek_peo.y = now.peoy + diry[i];
            if (seek_peo.x < 0 || seek_peo.x >= n || seek_peo.y < 0 || seek_peo.y >= m || coord[seek_peo.x][seek_peo.y] == '#')
                continue;
            if (seek_peo.x == now.binx && seek_peo.y == now.biny) {
                chess seek_bin;
                /*不小心推到箱子*/
                seek_bin.x = seek_peo.x + dirx[i];
                seek_bin.y = seek_peo.y + diry[i];
                if (seek_bin.x < 0 || seek_bin.x >= n || seek_bin.y < 0 || seek_bin.y >= m || coord[seek_bin.x][seek_bin.y] == '#')
                    continue;
                nxt.peox = seek_peo.x;
                nxt.peoy = seek_peo.y;
                nxt.binx = seek_bin.x;
                nxt.biny = seek_bin.y;
                nxt.step = now.step + 1;
                if(!vis[nxt.peox][nxt.peoy][nxt.binx][nxt.biny])
                    quu.push(nxt);
                vis[nxt.peox][nxt.peoy][nxt.binx][nxt.biny] = true;
            }
            else if (coord[seek_peo.x][seek_peo.y] == 'o') {
                nxt.peox = seek_peo.x;
                nxt.peoy = seek_peo.y;
                nxt.binx = now.binx;
                nxt.biny = now.biny;
                nxt.step = now.step + 1;
                if(!vis[seek_peo.x][seek_peo.y][now.binx][now.biny])
                    quu.push(nxt);
                vis[nxt.peox][nxt.peoy][nxt.binx][nxt.biny] = true;
            }

        }
    }
    printf("-1");
}

int main()
{
    memset(vis, 0, sizeof(vis));
    scanf("%d", &n);
    scanf("%d", &m);
    getchar();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%c", &coord[i][j]);
            if (coord[i][j] == 'X') {
                peo.x = i;
                peo.y = j;
                coord[i][j] = 'o';
            }
            if (coord[i][j] == '*') {
                bin.x = i;
                bin.y = j;
                coord[i][j] = 'o';
            }
            if (coord[i][j] == '@') {
                aim.x = i;
                aim.y = j;
                coord[i][j] = 'o';
            }
        }
        getchar();
    }
    BFS();
    return 0;
}

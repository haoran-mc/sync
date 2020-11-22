#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 101;
int n;
int m;
char water[maxn][maxn];
int puddle;
struct coord {
    int x;
    int y;
}chess;
queue<coord> quu;
int dirx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int diry[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
bool vis[maxn][maxn];

void BFS(int x, int y){
    vis[x][y] = true;
    for (int i = 0; i < 8; ++i)
        if (x+dirx[i] >= 0 && x+dirx[i] < n && y+diry[i] >= 0 && y+diry[i] < m && water[x+dirx[i]][y+diry[i]] == 'W' && !vis[x+dirx[i]][y+diry[i]]) {
                chess.x = x+dirx[i];
                chess.y = y+diry[i];
                quu.push(chess);
        }
}

int main()
{
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i < n; ++i)
        scanf("%s", water[i]);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (water[i][j] == 'W' && !vis[i][j]) {
                chess.x = i;
                chess.y = j;
                quu.push(chess);
                while (!quu.empty()) {
                    BFS(quu.front().x, quu.front().y);
                    quu.pop();
                }
                ++puddle;
            }

    printf("%d", puddle);
    return 0;
}

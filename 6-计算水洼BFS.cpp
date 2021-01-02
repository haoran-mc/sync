#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
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
vector<int> vec;
int dirx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int diry[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
bool vis[maxn][maxn];

void BFS(int x, int y) {
    vis[x][y] = true;
    for (int i = 0; i < 8; ++i)
        if (x+dirx[i] > 0 && x+dirx[i] <= n && y+diry[i] > 0 && y+diry[i] <= m && water[x+dirx[i]][y+diry[i]] == 'W' && !vis[x+dirx[i]][y+diry[i]]) {
            vis[x+dirx[i]][y+diry[i]] = true;
            chess.x = x + dirx[i];
            chess.y = y + diry[i];
            quu.push(chess);
        }
}

int main() {
    scanf("%d", &n);
    scanf("%d", &m);
    getchar();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            scanf("%c", &water[i][j]);
        getchar();
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (water[i][j] == 'W' && !vis[i][j]) {
                int size = 0;
                chess.x = i;
                chess.y = j;
                quu.push(chess);
                while (!quu.empty()) {
                    BFS(quu.front().x, quu.front().y);
                    quu.pop();
                    ++size;
                }
                ++puddle;
                vec.push_back(size);
            }
    printf("%d ", puddle);
    sort(vec.begin(), vec.end());
    for (auto it = vec.begin(); it != vec.end(); ++it)
        it == vec.end() - 1 ? printf("%d", *it) : printf("%d ", *it);
    return 0;
}

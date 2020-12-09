#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 2005;
const int inf  = 0x3f3f3f3f;
#define bug printf("<------>\n");
struct section {
    int left;
    int right;
    int tim;
} sect[maxn];

struct DP { //已初始化dp[0][t] = 0;
    int tim;
    bool flag;
} dp[maxn][50005];

bool cmp(section sect1, section sect2) {
    return sect1.right == sect2.right ? sect1.left < sect2.left : sect1.right < sect2.right;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    while (scanf("%d", &n) != EOF) {
        int minsect = inf;
        int minL = inf;
        int maxR = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d", &sect[i].left, &sect[i].right);
            sect[i].tim = sect[i].right - sect[i].left;
            minsect = min(minsect, sect[i].tim);
            minL = min(minL, sect[i].left);
            maxR = max(maxR, sect[i].right);
        }
        int maxT = maxR - minL;
        sort(sect, sect+n, cmp);

        for (int i = 1; i <= n; ++i)
            for (int t = 0; t <= maxT; ++t) {
            //for (int t = sect[i].tim; t <= maxT; ++t) {
                if (dp[i-1][t-sect[i].tim].flag == true && sect[i-1].right > sect[i].left)
                    dp[i][t].tim  = dp[i-1][t].tim,
                    dp[i][t].flag = false;
                else if (dp[i-1][t-sect[i].tim].flag == true && sect[i-1].right <= sect[i].left && t >= sect[i].tim && dp[i-1][t].tim < dp[i-1][t-sect[i].tim].tim + sect[i].tim)
                    dp[i][t].tim  = dp[i-1][t-sect[i].tim].tim + sect[i].tim,
                    dp[i][t].flag = true;
                else if (dp[i-1][t-sect[i].tim].flag == false && dp[i-1][t].tim < dp[i-1][t-sect[i].tim].tim + sect[i].tim && t >= sect[i].tim)
                    dp[i][t].tim  = dp[i-1][t-sect[i].tim].tim + sect[i].tim,
                    dp[i][t].flag = true;
                else
                    dp[i][t].tim  = dp[i-1][t].tim,
                    dp[i][t].flag = false;
            }

        printf("%d\n", dp[n][maxT].tim);
    }
    return 0;
}

#include <cstdio>
const int maxn = 105;
int num[maxn];
int dp[maxn];
int res;

int main() {
    int n;
    int m;
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", &num[i]);
    dp[0] = 1;
    for (int i = 0; i < n; ++i)
        for (int t = m; t >= 0; --t)
            if (t >= num[i])
                dp[t] += dp[t-num[i]];
    printf("%d", dp[m]);
    return 0;
}

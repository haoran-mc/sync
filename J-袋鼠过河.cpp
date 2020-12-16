#include <cstdio>
#include <vector>
using namespace std;

int main () {
    int n;
    scanf("%d", &n);
    vector<int> num(n, 0);
    for (int i = 0; i < n; ++i)
        scanf("%d", &num[i]);
    vector<int> dp(n + 1, n + 1);
    dp[0] = 0;
    for (int i = 0; i < n + 1; ++i)
        for (int j = i - 1; j >= 0; --j)
            if (j + num[j] >= i && dp[i] > dp[j] + 1)
                dp[i] = dp[j] + 1;
    dp[n] == n+1 ? printf("-1") : printf("%d", dp[n]);
    return 0;
}

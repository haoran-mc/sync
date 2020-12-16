#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
    scanf("%d", &n);
    vector<int> height(n, 0);
    int sum = 0;
    for (int i = 0; i < n; i++){
        scanf("%d", &height[i]);
        sum += height[i];
    }
    vector<vector<int> > dp(2, vector<int>(sum + 1, -1));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            int high = height[i - 1];
            dp[i & 1][j] = dp[(i - 1) & 1][j];
            if (j + high <= sum && dp[(i - 1) & 1][j + high] >= 0)
                dp[i & 1][j] = max(dp[i & 1][j], dp[(i - 1) & 1][j + high] + high);
            if (high - j >= 0 && dp[(i - 1) & 1][high - j] >= 0)
                    dp[i & 1][j] = max(dp[i & 1][j], dp[(i - 1) & 1][high - j] + high - j);
            if (j - high >= 0 && dp[(i - 1) & 1][j - high] >= 0)
                dp[i & 1][j] = max(dp[i & 1][j], dp[(i - 1) & 1][j - high]);
        }
    }
    dp[n & 1][0] ? printf("%d", dp[n & 1][0]) : printf("-1");
	return 0;
}

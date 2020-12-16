#include <cstdio>
const int maxn = 100005;
const int mod  = 1000007;
long long dp[maxn];

int main() {
    int num;
    int sum;
    scanf("%d", &num);
    scanf("%d", &sum);
    int array[num];
    for (int i = 0; i < num; i++)
        scanf("%d", &array[i]);

    for (int i = 0; i <= sum; i++)
        dp[i] = 0;

    for (int i = 0; i < num; i++){
        for (int j=sum;j>=0;j--)
            if (dp[j] > 0 && array[i]+j <= sum)
                dp[array[i]+j] += dp[j],
                dp[array[i]+j] %= mod;

        if (array[i] >= 0 && array[i] <= sum)
            dp[array[i]]++;
    }
    printf("%lld", dp[sum]);
    return 0;
}

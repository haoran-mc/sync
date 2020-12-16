#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 2100;
struct section {
    int left;
    int right;
} sect[maxn];
int dp[maxn];           //dp[i]为前i个活动能获得的最长活动时间
int n;

bool cmp(section x, section y) {
    return x.right < y.right;
}

int DP() {
    dp[0] = sect[0].right - sect[0].left;
    for(int i = 1; i < n; i++) {
        int max_res = sect[i].right - sect[i].left;
        for(int j = 0; j < i; j++)
            if(sect[j].right <= sect[i].left && dp[j] + sect[i].right - sect[i].left > max_res)
                max_res = dp[j] + sect[i].right - sect[i].left;
        dp[i] = max_res;
    }
    int max_r = 0;
    for(int i = 0; i < n; i++)
        if(dp[i] > max_r)
            max_r = dp[i];
    return max_r;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &sect[i].left, &sect[i].right);
    sort(sect, sect + n, cmp);
    printf("%d", DP());
    return 0;
}

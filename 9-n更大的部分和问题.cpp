#include <cstdio>
#include <unordered_set>
using namespace std;
typedef long long ill;
int arr[35];
bool DFS(int idx, int sum, int n, int k, unordered_set<ill> &unst) {
    unst.insert(sum);
    if (sum == k)
        return true;
    //if (sum > k)
        //return false;
    if (idx >= n)
        return false;
    if (DFS(idx+1, sum+arr[idx], n, k, unst))
        return true;
    if (DFS(idx+1, sum, n, k, unst))
        return true;
    return false;
}
int main()
{
    ill n;
    ill k;
    scanf("%lld", &n);
    scanf("%lld", &k);
    ill sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    //printf("%lld\n", sum-1);
    if (k == 0) {
        unordered_set<ill> unst;
        for (int i = 0; i < n; ++i)
            unst.insert(arr[i]);
        for (auto it = unst.begin(); it != unst.end(); ++it)
            if (unst.find(-*it) != unst.end()) {
                printf("Yes\n");
                return 0;
            }
        printf("No\n");
    }
    else if (n <= 15) {
        unordered_set<ill> unst;
        DFS(0, 0, n, k, unst) ? printf("Yes\n") : printf("No\n");
    }
    else {
        unordered_set<ill> unst1;
        unordered_set<ill> unst2;
        if (DFS(0, 0, 15, k, unst1)) {
            printf("Yes\n");
            return 0;
        }
        else if (DFS(15, 0, n, k, unst2)) {
            printf("Yes\n");
            return 0;
        }
        else {
            for (auto it = unst1.begin(); it != unst1.end(); ++it)
                if (unst2.find(k - *it) != unst2.end()) {
                    printf("Yes\n");
                    return 0;
                }
            //printf("unst1.size = %d\n", (int)unst1.size());
            //printf("unst2.size = %d\n", (int)unst2.size());
            //for (auto it = unst1.begin(); it != unst1.end(); ++it)
                //printf("%lld\n", *it);
            //printf("\n");
            //for (auto it = unst2.begin(); it != unst2.end(); ++it)
                //printf("%lld\n", *it);
            //printf("%lld\n", k);
            //printf("%lld\n", sum-1);
            printf("No\n");
        }
    }
    return 0;
}

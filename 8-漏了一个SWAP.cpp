#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
set<int> cnt1;
set<int> cnt2;
void Perm(int* arr, int n, int idx) {
    if (idx == n) {
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += arr[i];
            res *= 10;
        }
        res /= 10;
        cnt1.insert(res);
    }
    else {
        for(int i = idx; i < n; ++i) {
            swap(arr[i], arr[idx]);
            Perm(arr, n, idx+1);
            swap(arr[i], arr[idx]);
        }
    }
}

void WrongPerm(int* arr, int n, int idx) {
    if (idx == n) {
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += arr[i];
            res *= 10;
        }
        res /= 10;
        cnt2.insert(res);
    }
    else {
        for(int i = idx; i < n; ++i) {
            swap(arr[i], arr[idx]);
            WrongPerm(arr, n, idx+1);
        }
    }
}

int main()
{
    int n;
    //int arr[10];
    while (scanf("%d", &n) != EOF) {
        int* arr = (int *)malloc(n * sizeof(int));

        for (int i = 0; i < n; ++i)
            arr[i] = i;
        Perm(arr, n, 0);

        for (int i = 0; i < n; ++i)
            arr[i] = i;
        WrongPerm(arr, n, 0);

        printf("%d\n", (int)(cnt1.size() - cnt2.size()));
        cnt1.clear();
        cnt2.clear();
        free(arr);
    }
    return 0;
}

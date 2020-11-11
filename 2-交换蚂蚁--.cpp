#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1e8;
struct Ant{
    int pos;
    int to;
    int to_right;
    int to_left;
}arr[maxn];

bool cmp(Ant ant1, Ant ant2) {
    return ant1.pos < ant2.pos;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int L;
    int n;
    scanf("%d", &L);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i].pos);
        scanf("%d", &arr[i].to);
    }
    sort(arr, arr+n, cmp);
    //for (int i = 0; i < n; ++i)
        //printf("%d, %d, %d\n", arr[i].pos, arr[i].to, arr[i].sequ);
    int To_right = 0;
    int To_left  = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i].to == 1) {
            arr[i].to_left = To_left;
            To_right++;
        }
        else if (arr[i].to == 0) {
            arr[i].to_right = To_right;
            To_left++;
        }
    }

    int tim = 0;
    int ant = 0;
    for (int i = 0; i < n; ++i) {
        if ((arr[i].to == 1) && (tim <= (L - arr[i].pos))) {
            tim = L - arr[i].pos;
            ant = i;
        }
        else if ((arr[i].to == 0) && (tim < arr[i].pos)) {
            tim = arr[i].pos;
            ant = i;
        }
    }

    if (arr[ant].to == 1)
        ant += (To_left - arr[ant].to_left);
    else
        ant -= arr[ant].to_right;
    printf("%d %d", ant, tim);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
struct stick{
    int x, y;
} st[5005];
int n, i, j, m, f[5005];
int cmp(stick a, stick b) {
    return (a.x > b.x || (a.x == b.x && a.y > b.y)) ? 1 : 0;
}
int main() {
    cin >> n;
    while (cin >> st[i].x >> st[i].y)
        f[i++] = 1;
    sort(st, st+n, cmp);
    for (i = 0; i < n; ++i)
        for (j = 0; ++j < i;)
            if (st[i].y > st[j].y)
                f[i] = max(f[i], f[j]+1),
                m = max(m, f[i]);
    cout << m;
}

#include <iostream>
#include <algorithm>
using namespace std;
struct stick{
    int x, y;
} st[5005];
int n, i, j, m, f[5005];
int main() {
    cin >> n;
    while (cin >> st[i].x >> st[i].y)
        f[i++] = 1;
    sort(st, st+n, [](stick a, stick b) -> int {return a.x > b.x;});
    for (i = 0; i < n; ++i)
        for (j = 0; ++j < i;)
            if (st[i].y > st[j].y)
                f[i] = max(f[i], f[j]+1),
                m = max(m, f[i]);
    cout << m;
}

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 3005;
int pos[maxn];
vector<int> vec;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    int m;
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", &pos[i]);
    sort(pos, pos+n);
    for (int i = 0; i < n-1; ++i)
        if (pos[i+1]-1 - pos[i])
            vec.push_back(pos[i+1]-1 - pos[i]);
    sort(vec.begin(), vec.end());
    int sum = 0;
    for (int i = 0; i < (int)vec.size()-m+1; ++i)
        sum += vec[i];
    printf("%d", sum + n);
    return 0;
}

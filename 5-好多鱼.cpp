#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1e5;
vector<int> fish(maxn, 0);
int main()
{
    int left;
    int right;
    int n;
    scanf("%d", &left);
    scanf("%d", &right);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &fish[i]);
    int res = 0;
    for (int i = left; i <= right; ++i) {
        bool flag = true;
        for (auto it = fish.begin(); it != fish.begin()+n; ++it) {
            if (i <= *it * 10 && i >= *it * 2)
                flag = false;
            else if (!(*it % 10) && i >= *it/10 && i <= *it/2)
                flag = false;
            else if ((*it % 10) && !(*it % 2) && i > *it/10 && i <= *it/2)
                flag = false;
            else if ((*it % 10) && (*it % 2) && i > *it/10 && i < *it/2)
                flag = false;
        }
        if (flag) ++res;
    }
    printf("%d", res);
    return 0;
}


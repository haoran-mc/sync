#include <cstdio>
#include <algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
int arr[4];
int main() {
    int warn;
    int subp;
    int maxp = 0;
    int flag = 0;
    for (int i = 0; i < 4; ++i) {
        scanf("%d", &arr[i]);
        maxp = max(maxp, arr[i]);
    }
    scanf("%d", &warn);
    scanf("%d", &subp);
    for (int i = 0; i < 4; ++i)
        if (arr[i] < warn || arr[i] < maxp - subp)
            ++flag;
    if (flag == 0)
        printf("Normal");
    else if (flag > 1)
        printf("Warning: please check all the tires!");
    else {
        for (int i = 0; i < 4; ++i)
            if (arr[i] < warn || arr[i] < maxp - subp)
                printf("Warning: please check #%d!", i + 1);
    }
    return 0;
}


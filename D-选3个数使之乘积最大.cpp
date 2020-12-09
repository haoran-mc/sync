#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> vec;
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end());
    if (vec[n-1] <= 0)
        printf("%d", vec[n-1] * vec[n-2] * vec[n-3]);
    else {
        int sumFront  = vec[0] * vec[1] * vec[n-1];
        int sumBehind = vec[n-1] * vec[n-2] * vec[0];
        printf("%d", sumFront < sumBehind ? sumBehind : sumFront);
    }
    return 0;
}


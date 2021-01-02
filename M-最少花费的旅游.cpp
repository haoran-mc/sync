#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;

struct gasStation {
    int dist;
    int cost;
};

int cmp(gasStation A, gasStation B) {
    return A.dist < B.dist;
}

int main() {
    priority_queue <int, vector <int>, greater<int> > pqu;
    int n;
    int L, P;
    LL pay = 0;
    scanf("%d", &n);
    scanf("%d", &L);
    scanf("%d", &P);
    vector<gasStation> station(n + 1);
    station[n].dist = L;
    station[n].cost = 0;
    for (int i = 0; i < n; ++i)
        scanf("%d %d", &station[i].dist, &station[i].cost);
    sort(station.begin(), station.end(), cmp);
    for (int i = 0; i <= n; ++i) {
        if (station[i].dist <= P)
            pqu.push(station[i].cost);
        else if (pqu.empty()) {
            printf("-1");
            return 0;
        }
        else {
            pay += (station[i].dist-P) * pqu.top();
            P = station[i].dist;
            pqu.push(station[i].cost);
        }
    }
    printf("%lld", pay);
    return 0;
}

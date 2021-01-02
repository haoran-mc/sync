#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int noequal = maxn / 2;
int parent[maxn];
int Rank[maxn];

void init() {
    for(int i = 0; i < maxn; i++){
        parent[i] = i;
        Rank[i] = 0;
    }
}

int find_root(int x) {
    return parent[x] == x ? x : parent[x] = find_root(parent[x]);
}

bool update(int x, int y) {
    int x_root = find_root(x);
    int y_root = find_root(y);

    if (x_root == y_root)
        return false;
    if (Rank[x_root] > Rank[y_root])
        parent[y_root] = x_root;
    else{
        parent[x_root] = y_root;
        if (Rank[x_root] == Rank[y_root])
            Rank[y_root]++;
    }
    return false;
}

int judge(int x, int y) {
    return find_root(x) == find_root(y);
}

int main() {
    int n;
    scanf("%d", &n);
    init();
    for(int i = 0; i < n; i++) {
        int x, y, e;
        cin >> x >> y >> e;
        x = x - 1;
        y = y - 1;
        if (e) {
            if (judge(x, y + noequal)) {
                printf("NO");
                return 0;
            }
            update(x, y);
            update(x + noequal, y + noequal);
        }
        else {
            if (judge(x, y) || judge(x + noequal, y + noequal)){
                printf("NO");
                return 0;
            }
            update(x, y + noequal);
            update(x + noequal, y);
        }
    }
    printf("YES");
}

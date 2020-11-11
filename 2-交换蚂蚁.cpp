#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define bug printf("******\n");

const int inf = 0x3f3f3f3f;
struct Ant{
    int pos;
    int to;
    int to_right;
    int to_left;
};
vector<Ant> vec;
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
        Ant ant;
        scanf("%d", &ant.pos);
        scanf("%d", &ant.to);
        vec.push_back(ant);
    }
    sort(vec.begin(), vec.end(), cmp);
    //for (int i = 0; i < n; ++i)
        //printf("%d, %d, %d\n", vec[i].pos, vec[i].to, vec[i].sequ);
    int To_right = 0;
    int To_left  = 0;
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        if (it -> to == 1) {
            it -> to_left = To_left;
            To_right++;
        }
        else if (it -> to == 0) {
            it -> to_right = To_right;
            To_left++;
        }
    }

    int tim = vec[0].to==1?L-vec[0].pos:vec[0].pos;
    int ant = 0;
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        if ((it -> to == 1) && (tim <= (L - it->pos))) {
            tim = L - it->pos;
            ant = it-vec.begin();
        }
        else if ((it -> to == 0) && (tim < it-> pos)) {
            tim = it->pos;
            ant = it-vec.begin();
        }
    }

    if (vec[ant].to == 1)
        ant += (To_left - vec[ant].to_left);
    else
        ant -= vec[ant].to_right;
    printf("%d %d", ant, tim);
    return 0;
}


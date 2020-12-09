#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 205;
struct Grade {
    int score;
    int tim;
} grade[maxn];

bool cmp(Grade grade1, Grade grade2) {
    return grade1.tim < grade2.tim;
}

int main()
{
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &grade[i].score, &grade[i].tim);
        sum += grade[i].score;
    }
    int marks;
    double avg;
    scanf("%d %lf", &marks, &avg);
    avg = n * avg;
    sort(grade, grade+n, cmp);
    int sumTim = 0;
    for (int i = 0; i < n && sum < avg; ++i)
        while (grade[i].score < marks && sum < avg) {
            ++grade[i].score;
            sumTim += grade[i].tim;
            ++sum;
        }
    printf("%d", sumTim);
    return 0;
}


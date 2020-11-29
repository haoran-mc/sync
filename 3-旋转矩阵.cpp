#include <cstdio>
const int maxn = 51;
int matrix[maxn][maxn];

bool judge(int left, int right, int up, int down) {
    return up <= down && left <= right;
}

int getRight(int num) {
    int right = 1;
    while (num /= 10)
        ++right;
    return right;
}

void output(int Max, int n) {
    int right  = getRight(Max);
    int fricol = getRight(4*n-4);
    switch(right) {
        case 1:
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    j == 1 ? printf("%d", matrix[i][j]) : printf("%2d", matrix[i][j]);
                }
                printf("\n");
            }
            break;
        case 2:
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j)
                    if (right == fricol)
                        j == 1 ? printf("%2d", matrix[i][j]) : printf("%3d", matrix[i][j]);
                    else
                        j == 1 ? printf("%d", matrix[i][j]) : printf("%3d", matrix[i][j]);
                printf("\n");
            }
            break;
        case 3:
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j)
                    if (right == fricol)
                        j == 1 ? printf("%3d", matrix[i][j]) : printf("%4d", matrix[i][j]);
                    else
                        j == 1 ? printf("%2d", matrix[i][j]) : printf("%4d", matrix[i][j]);
                printf("\n");
            }
            break;
        case 4:
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j)
                    if (right == fricol)
                        j == 1 ? printf("%4d", matrix[i][j]) : printf("%5d", matrix[i][j]);
                    else
                        j == 1 ? printf("%3d", matrix[i][j]) : printf("%5d", matrix[i][j]);
                printf("\n");
            }
            break;
    }
}

int main()
{
    int n;
    while (scanf("%d", &n) && n) {
        int left  = 1;
        int right = n;
        int down  = n;
        int up    = 1;
        int num   = 1;
        int x     = 1;
        int y     = 1;
        int Max   = 0;
        while (left <= right && up <= down) {
            for (y = left; y <= right && judge(left, right, up, down); ++y)
                matrix[x][y] = num++;
            --y;
            ++up;
            for (x = up; x <= down && judge(left, right, up, down); ++x)
                matrix[x][y] = num++;
            --x;
            --right;
            for (y = right; y >= left && judge(left, right, up, down); --y)
                matrix[x][y] = num++;
            ++y;
            --down;
            for (x = down; x >= up && judge(left, right, up, down); --x)
                matrix[x][y] = num++;
            ++x;
            ++left;
            Max = num - 1;
        }
        output(Max, n);
    }
    return 0;
}


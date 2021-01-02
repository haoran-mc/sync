#include <cstdio>
int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d\n", 5000 - 50*(100-x) - 50*y);
    return 0;
}

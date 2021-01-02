#include <cstdio>
#include <cmath>
using namespace std;
const double eps = 1e-8;
double a3, a2, a1, a0;
double a, b;

double f(double x) {
    return a3*pow(x, 3) + a2*pow(x, 2) + a1*pow(x, 1) + a0*pow(x, 0);
}

double root(double L, double R) {
    double mid = (L + R) / 2;
    if (fabs(f(mid)) < eps)
        return mid;
    else if (f(mid) * f(L) > 0)
        return root(mid, R);
    else
        return root(L, mid);
}

int main() {
    scanf("%lf %lf %lf %lf", &a3, &a2, &a1, &a0);
    scanf("%lf %lf", &a, &b);
    double res = root(a, b);
    printf("%.2f\n", res);
    return 0;
}

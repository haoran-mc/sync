#include <cstdio>
#include <cmath>
const double eps = 1e-6;
double a;
double b;
double c;
double d;

double equation(double x) {
    return a*pow(x, 3) + b*pow(x, 2) + c*pow(x, 1) + d;
}

int main()
{
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);
    scanf("%lf", &d);
    int flag = 0;
    for (double i = -100; i <= 100 && flag != 3; i++) {
        double x1 = i;
        double x2 = i + 1;
        if (!equation(i)) {
            printf("%.2f", i);
            if (++flag != 3) printf(" ");
        }
        else if (equation(x1) * equation(x2) < 0) {
            while (fabs(x2-x1) >= eps) {
                double mid = (x1 + x2) / 2;
                equation(x1) * equation(mid) <= 0 ? x2 = mid : x1 = mid;
            }
            printf("%.2f", x1);
            if (++flag != 3) printf(" ");
        }
    }
    return 0;
}

#include <iostream>
#include <string>
using namespace std;
string str;
const int maxn = 10005;
int dp[55][maxn]; //dp[i][j]前i位字符串%n等于j的情况数

int main() {
    int n;
    cin >> str >> n;
    if (str[0] == 'X') {
        for (int j = 0; j <= n - 1; j++) //枚举余数
            for (int i = 0; i <= 9; i++)
                if (i % n == j)
                    dp[1][j]++;
    }
    else {
        int x = str[0] - '0';
        int j = x % n;
        dp[1][j]++;
    }
    //后面的位数
    for (int i = 2; i <= (int)str.length(); i++) {
        for (int j = 0; j <= n-1; j++) {
            if (str[i - 1] == 'X') {
                for (int k = 0; k <= 9; k++) {
                    //这里要理解状态转移
                    int newj = (10*j+k) % n;
                    dp[i][newj] += dp[i-1][j];
                }
            }
            else {
                int newj = (10*j+str[i-1]-'0')%n;
                dp[i][newj] += dp[i-1][j];
            }
        }
    }
    printf("%d", dp[str.length()][0]);
    return 0;
}

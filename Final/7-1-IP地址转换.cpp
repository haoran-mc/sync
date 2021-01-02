#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

void convert(string str, vector<int> &vec) {
    for (int i = 0; i < 8; ++i)
        vec.push_back(str[i] - 48);
}

int anytoD(vector<int> &num, int base) {
    reverse(num.begin(), num.end());
    int numD = 0;
    for (int i = 0; i < (int)num.size(); ++i)
        numD += (num[i] * pow(base, i));
    num.clear();
    return numD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string str;
    cin >> str;
    string str1 = str.substr(0, 8);
    string str2 = str.substr(8, 8);
    string str3 = str.substr(16, 8);
    string str4 = str.substr(24, 8);
    vector<int> vec;
    convert(str1, vec);
    int numD = anytoD(vec, 2);
    cout << numD << ".";

    convert(str2, vec);
    numD = anytoD(vec, 2);
    cout << numD << ".";

    convert(str3, vec);
    numD = anytoD(vec, 2);
    cout << numD << ".";

    convert(str4, vec);
    numD = anytoD(vec, 2);
    cout << numD << endl;
    return 0;
}

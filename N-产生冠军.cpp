#include <iostream>
#include <set>
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n;
    set<string> All;
    set<string> loser;
    string str1;
    string str2;
    while(n--) {
        cin >> str1 >> str2;
        All.insert(str1);
        loser.insert(str2);
        All.insert(str2);
    }
    cout << (All.size() - loser.size() == 1 ? "Yes" : "No");
    return 0;
}

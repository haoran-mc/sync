#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct Info {
    string name;
    string birt;
    char gend;
    string stic;
    string mobile;
};

int main() {
    int n;
    cin >> n;
    vector<Info> vec;
    for (int i = 0; i < n; ++i) {
        Info info;
        cin >> info.name
            >> info.birt
            >> info.gend
            >> info.stic
            >> info.mobile;
        vec.push_back(info);
    }
    int t;
    cin >> t;
    while (t--) {
        int seek;
        cin >> seek;
        if (seek >= (int)vec.size() || seek < 0) {
            cout << "Not Found" << endl;
            continue;
        }
        cout << vec[seek].name << " "
             << vec[seek].stic << " "
             << vec[seek].mobile << " "
             << vec[seek].gend << " "
             << vec[seek].birt << endl;
    }
    return 0;
}

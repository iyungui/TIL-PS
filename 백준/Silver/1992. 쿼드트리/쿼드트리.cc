#include<bits/stdc++.h>
using namespace std;

string a[66];
int n;
string go(int y, int x, int size) {
    string start = (a[y][x] == '1') ? "1" : "0";
    if(size == 1) return start;
    bool flag = true;
    for(int i = y; i < y + size; i++) {
        for(int j = x; j < x + size; j++) {
            if(a[y][x] != a[i][j]) {
                flag = false;
                break;
            }
        }
        if(!flag) break;
    }
    if(flag) return start;

    string ret = "";
    ret += "(";
    ret += go(y, x, size / 2);
    ret += go(y, x + (size / 2), size / 2);
    ret += go(y + (size / 2), x, size / 2);
    ret += go(y + (size / 2), x + (size / 2), size / 2);
    ret += ")";
    return ret;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << go(0, 0, n) << '\n';
    return 0;
}
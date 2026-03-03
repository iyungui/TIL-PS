/*
첫번째 문자열의 앞에서부터 i개까지 봤을때 LCS
두번째 문자열의 앞에서부터 j개까지 봤을때 LCS

d[i][j] = d[i-1][j-1]+1 (x[i] == y[j])
d[i][j] = max(d[i-1][j], d[i][j-1]) (x[i]!=y[j])

d[i][0] = 0
d[0][j] = 0
*/

#include<bits/stdc++.h>
using namespace std;

string x, y;
int d[1004][1004];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> x >> y;

    int a = x.size();
    int b = y.size();

    for(int i = 1; i <= a; i++) {
        for(int j = 1; j <= b; j++) {
            if(x[i-1] == y[j-1]) d[i][j] = d[i-1][j-1] + 1;
            else d[i][j] = max(d[i-1][j], d[i][j-1]);
        }
    }

    int i = a;
    int j = b;
    string ret = "";
    while(1) {
        if(i == 0 || j == 0) break;
        if(x[i-1] == y[j-1]) {
            ret = x[i-1] + ret;
            i--;
            j--;
        }
        else {
            if(d[i-1][j] >= d[i][j-1]) {
                i--;    // up
            }
            else {
                j--;    // left
            }
        }
    }

    cout << d[a][b] << '\n';
    cout << ret << '\n';
    return 0;
}
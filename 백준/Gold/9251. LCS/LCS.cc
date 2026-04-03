#include<bits/stdc++.h>

using namespace std;

int d[1004][1004];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string x, y; 
    cin >> x >> y;
    int a = x.size();
    int b = y.size();

    for(int i = 1; i <= a; i++) {
        for(int j = 1; j <= b; j++) {
            if(x[i-1] == y[j-1]) {
                d[i][j] = d[i-1][j-1] + 1;
            }
            else {
                d[i][j] = max(d[i-1][j], d[i][j-1]);
            }
        }
    }
    int i = a;
    int j = b;
    cout << d[i][j] << '\n';
    return 0;
}
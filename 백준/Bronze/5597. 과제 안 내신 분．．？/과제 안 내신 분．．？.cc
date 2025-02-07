#include <bits/stdc++.h>
using namespace std;
const int n = 28;
int a[31], temp;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for(int i = 0; i < n; i++) {
        cin >> temp;
        a[temp]++;
    }
    for(int i = 1; i <= 30; i++) {
        if(!a[i]) {
            cout << i << '\n';
        }
    }
    return 0;
}
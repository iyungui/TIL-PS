#include <bits/stdc++.h>
using namespace std;

const int n = 9;
int ret, idx, temp;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for(int i = 0; i < n; i++) {
        cin >> temp;
        if(ret < temp) idx = i, ret = temp;
    }
    cout << ret << '\n' << idx + 1 << '\n';
    return 0;
}
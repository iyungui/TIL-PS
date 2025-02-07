#include <bits/stdc++.h>
using namespace std;
const int n = 42;
int temp, cnt[n], ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for(int i = 0; i < 10; i++) {
        cin >> temp;
        cnt[temp%n]++;
    }
    for(int i = 0; i < n; i++) {
        if(cnt[i]) ret++;
    }
    cout << ret << '\n';
    return 0;
}
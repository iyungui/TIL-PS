#include <bits/stdc++.h>
using namespace std;
int temp, cnt[1000], ret;
const int n = 42;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for(int i = 0; i < 10; i++) {
        cin >> temp;
        cnt[temp%n]++;
    }
    for(int i = 0; i < 1000; i++) {
        if(cnt[i]) ret++;
    }
    cout << ret << '\n';
    return 0;
}
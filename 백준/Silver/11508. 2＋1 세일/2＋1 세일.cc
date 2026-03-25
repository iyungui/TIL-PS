#include <bits/stdc++.h>

using namespace std;

int n;
int a[100004];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, greater<int>());
    int group_count = (n + 2) / 3;

    long long ret = 0;
    for(int i = 0; i < group_count; i++) {
        if(i == group_count - 1) {
            int j = 0;
            while(i*3+j < n) {
                if(j == 2) break;
                ret += a[i*3+j];
                j++;
            }
            continue;
        }
        for(int j = 0; j < 2; j++) {
            ret += a[i * 3 + j];
        }
    }
    cout << ret << '\n';
    return 0;
}
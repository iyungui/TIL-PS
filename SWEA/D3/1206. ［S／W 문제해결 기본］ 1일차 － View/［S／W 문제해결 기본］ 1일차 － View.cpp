#include<bits/stdc++.h>

using namespace std;

const int T = 10;
int n;
int a[1004];
int l, r, temp;

int main() {
    for(int t = 1; t <= T; t++) {
        cin >> n;
        memset(a, 0, sizeof(a));
        for(int i = 0; i < n; i++) cin >> a[i];
        int sum = 0;
        for(int i = 2; i < n - 2; i++) {
            l = max(a[i - 1], a[i - 2]);
            r = max(a[i + 1], a[i + 2]);
            temp = a[i] - max(l, r);
            if(temp < 0) temp = 0;
            sum += temp;
        }
        cout << "#" << t << " " << sum << '\n';
    }
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int T, n, m;
int a[24], b[24];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> n >> m;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < m; i++) cin >> b[i];
        bool flag = n < m;
        int diff = abs(n - m);
        int ret = 0;

        for(int i = 0; i <= diff; i++) {
            int sum = 0;
            for(int j = 0; j < n; j++) {
                if(flag) sum += (a[j] * b[j + i]);
                else sum += (a[j + i] * b[j]);
            }
            
            ret = max(ret, sum);
        }
        cout << "#" << t << " " << ret << '\n';
    }
    return 0;
}
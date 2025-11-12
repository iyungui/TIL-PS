#include<bits/stdc++.h>
using namespace std;

int T, n;
int a[54][54];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> T;

    for(int t = 1; t <= T; t++) {
        // input
        cin >> n;
        memset(a, 0, sizeof(a));

        string s;
        for(int i = 0; i < n; i++) {
            cin >> s;
            for(int j = 0; j < n; j++) {
                a[i][j] = (int)s[j] - '0';
            }
        }

        int ret = 0;
        int mid = n / 2;
        for(int i = 0; i < n; i++) {
            int j = (i <= mid) ? i : n - 1 - i;

            int sum = a[i][mid];
            for(int k = 1; k <= j; k++) {
                ret += a[i][mid - k];
                ret += a[i][mid + k];
            }
            ret += sum;
        }

        cout << "#" << t << " " << ret << '\n';
    }
}
#include<bits/stdc++.h>

using namespace std;

const int TC = 10;
const int n = 100;
int dump;
int a[n];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for(int t = 1; t <= TC; t++) {
        cin >> dump;
        for(int i = 0; i < n; i++) cin >> a[i];

        while(dump--) {
            sort(a, a + n);
            a[n - 1]--;
            a[0]++;
            if(a[n - 1] - a[0] <= 1) break; 
        }
        sort(a, a + n);
        int ret = a[n - 1] - a[0];
        cout << "#" << t << " " << ret << '\n';
    }

    return 0;
}
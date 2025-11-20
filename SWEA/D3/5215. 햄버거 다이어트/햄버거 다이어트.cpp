#include<bits/stdc++.h>
using namespace std;

int T;
int n, l;
int a[24], k[24];
int ret;
void go(int i, int kcal, int sum) {
    if(i == n) {
        ret = max(ret, sum);
        return;
    }
    go(i+1, kcal, sum);
    if(kcal + k[i] <= l) {
        go(i+1, kcal + k[i], sum + a[i]);
    }
}

int main() {
    cin >> T;   
    for(int t = 1; t <= T; t++) {
        memset(a, 0, sizeof(a));
        memset(k, 0, sizeof(k));

        ret = 0;
        cin >> n >> l;

        for(int i = 0; i < n; i++) {
            cin >> a[i] >> k[i];
        }
        go(0, 0, 0);

        cout << "#" << t << " " << ret << '\n';
    }
}
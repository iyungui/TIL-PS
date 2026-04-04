#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, C, a[31], ret;
vector<int> v, v2;
void go(int here, int n, vector<int>& v, int sum) {
    if(sum > C) return;
    if(here > n) {
        v.push_back(sum);
        return;
    }
    go(here + 1, n, v, sum + a[here]);
    go(here + 1, n, v, sum);
    return;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> C;
    for(int i = 0; i < N; i++) cin >> a[i];
    go(0, N / 2 - 1, v, 0);
    go(N/2, N-1,v2,0);
    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end());
    for(int b: v) {
        if(C - b >= 0) ret += ((int)(upper_bound(v2.begin(), v2.end(), C-b) - v2.begin()));
    }
    cout << ret << '\n';
    return 0;
}
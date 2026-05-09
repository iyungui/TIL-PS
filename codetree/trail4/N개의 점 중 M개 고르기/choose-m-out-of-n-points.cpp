#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// n개 중 m개의 점을 선택
// m개 중 두 점 선택하여 최대 거리 구하기
// 그 최대거리의 최솟값 구하기
int n, m;
pair<int, int> dots[22];
int chosen[22];
ll ret = 1e9;

ll get_dist(int a, int b) {
    int x = abs(dots[a].first - dots[b].first);
    int y = abs(dots[a].second - dots[b].second);
    return x*x + y*y;
}

ll get_max_dist() {
    ll res = 0;
    for(int i = 0; i < m; i++) {
        for(int j = i+1; j < m; j++) {
            res = max(res, get_dist(chosen[i], chosen[j]));
        }
    }
    return res;
}

// 몇번째 점 고려중인지cur
// 몇개 골랐는지 cnt
void go(int cur, int cnt) {
    if(cnt == m) {
        ret = min(ret, get_max_dist());
        return;
    }
    if(cur >= n) return;
    if(n-cur < m-cnt) return;
    chosen[cnt] = cur;
    go(cur+1,cnt+1);
    go(cur+1,cnt);
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> dots[i].first >> dots[i].second;
    }
    go(0, 0);
    cout << ret << '\n';
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
// 적어도 m미터 나무를 가질 수 있는. 절단기 높이의 최댓값을 구하는 문제
// 절단기 높이를 h라고 하면
// h가 커질 수록 가져갈 수 있는 나무길이 len은 작아진다는 단조성 존재

bool chk(int h, vector<ll>& trees, ll m) {
    ll len = 0;
    for(ll t : trees) {
        if(t > h) len += (t-h);
    }
    return len >= m;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<ll> trees(n);
    ll lo = 0;
    ll hi = 0;
    for(int i = 0; i < n; i++) {
        cin >> trees[i];
        hi = max(hi, trees[i]);
    }

    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        // 절단기 높이를 mid로 했을 때 m만큼 가져갈 수 있는지 체크
        if(chk(mid, trees, m)) {
            //m이상 가져갈 수 있다면, 더 큰 절단기높이mid로 시도
            lo = mid+1;
        }
        //더 작은 절단기 높이로 시도
        else hi = mid-1;
    }
    cout << hi << '\n';

    return 0;
    
}
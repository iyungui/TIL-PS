#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
ll s;
int a[100004];
int ret = 1e9;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> s;
    // 수열 중 연속된 수들의 부분합이, S이상이 되는 것들
    // 그 중 가장 짧은 것의 길이

    for(int i = 0; i < n; i++) cin >> a[i];

    int l = 0, r = 0;
    ll sum = 0;
    // r 을 하나씩 오른쪽으로 옮기며 sum 에 a[r] 더하기
    // sum이 s 이상이 되면 그 동안의 길이를 저장된 ret와 비교해 최소길이로 갱신
    // sum이 s 미만이 될 때까지 l을 오른쪽으로 옮기며 sum에서 a[l]을 빼고, 뺄 때마다 길이 다시 체크
    // r이 끝까지 갈 때까지 반복

    while(r < n) {
        sum += a[r];
        while(sum >= s) {
            ret = min(ret, r-l+1);
            sum -= a[l];
            l++;
        }
        r++;
    }
    if(ret == 1e9) cout << 0 << '\n';
    else cout << ret << '\n';
    return 0;
}
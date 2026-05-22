#include <bits/stdc++.h>
using namespace std;

int n, A[100004];
int main() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int ret = A[0];
    int cur = A[0];
    // i번째원소만 vs i-1번째원소까지 부분수열합+ i번째 원소
    // 만약 i번째원소가 더 크면, i-1번째원소까지 부분수열합이 음수라는 뜻이므로, i번째 원소부터 다시 시작
    for(int i = 1; i < n; i++) {
        cur = max(A[i], cur + A[i]);
        ret = max(ret, cur);
    }

    cout << ret << '\n';
    return 0;
}
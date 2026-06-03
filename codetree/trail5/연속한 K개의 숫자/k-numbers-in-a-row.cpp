#include <bits/stdc++.h>
using namespace std;

int n, k, b;

int main() {
    cin >> n >> k >> b;

    // n+1의 전체 구간에 false(숫자가 원래 있음) 으로 초기화
    vector<bool> A(n+1, false);

    // b개의 숫자가 있는 공간마다 true(숫자가 없음) 으로 초기화
    for(int i = 0; i < b; i++) {
        int num; cin >> num;
        A[num] = true;
    }
    // 1부터 k까지의 구간에서 추가해야 하는 숫자의 개수 구하기
    int cnt = 0;
    for(int i = 1; i <= k; i++) {
        if(A[i]) cnt++;
    }
    int l = 1;  // l 위치: 1에서 시작
    int r = k+1;
    int ret = 1e9;
    while(r <= n) {
        if(A[r++]) cnt++; // 새 구간에서 숫자가 없는경우
        if(A[l++]) cnt--; // 빠져나갈 구간에서 숫자가 없는경우

        ret = min(ret, cnt);
    }
    cout << ret << '\n';
    return 0;
}
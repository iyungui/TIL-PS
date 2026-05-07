#include <bits/stdc++.h>
using namespace std;

int n, m, ret;
int a[24];

// 몇번째로 뽑는 숫자인지(cnt), 몇번째인덱스부터 뽑아야 하는지(cur_idx), 현재까지의 xor 값(val)
void findMaxXor(int cnt, int cur_idx, int cur_val) {
    if(cnt == m) {  // m개를 다 선택한 경우 최댓값 갱신
        ret = max(ret, cur_val);
        return;
    }

    // 남은 원소의 개수가 부족하면 종료 (가지치기)
    if(cur_idx >= n || (n-cur_idx) < (m-cnt)) return;

    // cur_idx번째 숫자를 선택하는 경우
    findMaxXor(cnt+1, cur_idx+1, cur_val ^ a[cur_idx]);
    // 선택하지 않는 경우
    findMaxXor(cnt, cur_idx+1, cur_val);
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    findMaxXor(0, 0, 0);
    cout << ret << '\n';
    return 0;
}
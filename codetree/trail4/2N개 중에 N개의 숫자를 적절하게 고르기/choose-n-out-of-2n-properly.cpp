#include <bits/stdc++.h>
using namespace std;

// 2n개 전체원소의 total sum을 구한다
// n개를 뽑는 조합 -> sum을 구한다
// 나머지 n개의 합은 total_sum - sum 이다

int n;
int total;
int nums[24];
int ret = 1e9;
// 몇번째를 고려중인지idx
// 몇개를 뽑았는지 cnt
// 현재까지의 합 sum
void go(int idx, int cnt, int sum) {
    if(idx >= 2*n) return;
    if(cnt == n) {
        int other = total - sum;
        ret = min(ret, abs(other - sum));
        return;
    }

    if((2*n - idx) < (n - cnt)) return;

    go(idx+1, cnt+1, sum+nums[idx]);
    go(idx+1, cnt, sum);
}

int main() {
    cin >> n;
    for(int i = 0; i < 2*n; i++) {
        cin >> nums[i];
        total += nums[i];
    }
    go(0, 0, 0);
    cout << ret << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n, A[100004];
int main() {
    int n; cin >> n;
    bool flag = 0;  // 양수가 하나라도 있다면 true
    for(int i = 0; i < n; i++) {
        cin >> A[i];
        if(A[i] > 0) flag = 1;
    }
    if(!flag) { // 양수가 없는 경우, 가장 큰 숫자 하나만 선택하는 것이 최선
        cout << *max_element(A, A + n) << '\n';
        return 0;
    }
    // 양수가 하나 이상 존재한다면,
    // i-1번째 까지의 합이 음수라면, 0에서 시작하는 것이 최선이고
    // 양수라면 해당 합에 i번째원소를 더해보기.(i-1번째에서 i번째 원소를 더했을때 값이 줄어들더라도, i+1번째 이후에 최대값이 나올 수 있음.)
    int ret = A[0];
    int cur = A[0];
    for(int i = 1; i < n; i++) {
        // 새로 시작?
        // 합치기?
        if(cur < 0) cur = A[i];
        else cur += A[i];

        ret = max(ret, cur);
    }

    cout << ret << '\n';
    return 0;
}
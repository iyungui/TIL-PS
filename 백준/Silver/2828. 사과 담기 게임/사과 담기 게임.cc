#include <bits/stdc++.h>

using namespace std;

int n, m, j, l, r, temp, ret;

int main() {
    cin >> n >> m >> j;
    
    l = 1;  // 바구니의 왼쪽 부분
    for(int i = 0; i < j; i++) {
        r = l + m - 1;  // 바구니의 오른쪽 부분 (업데이트된 l 기반으로 매 j마다 갱신)
        cin >> temp;
        if(temp >= l && temp <= r) continue;
        else {
            if(temp < l) {  // 만약 사과 위치보다 바구니가 오른쪽에 있는 경우, 바구니 뒤로 가야함
                ret += (l - temp);
                l = temp;
            } else {    // 만약 사과 위치보다 바구니가 왼쪽에 있다면, 바구니 앞으로(오른쪽으로)
                ret += (temp - r);
                l += (temp - r);
            }
        }
    }
    
    cout << ret << '\n';
    return 0;
}

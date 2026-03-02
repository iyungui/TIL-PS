#include<bits/stdc++.h>
using namespace std;

int n;
int ret = -1e9;
int num, sum;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num;
        sum = max(sum+num, num);    // 현재 수만 선택 vs sum+현재수 선택
        ret = max(ret, sum);
    }
    cout << ret << '\n';
    return 0;
}

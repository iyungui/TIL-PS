
#include <bits/stdc++.h>
using namespace std;

int t, n;
string a, b;

int main() {
    cin >> t;
    while(t--) {
        map<string, int> mp;
        cin >> n;   // 의상의 개수
        
        for(int i = 0; i < n; i++) {
            cin >> a >> b;  // 의상 이름, 종류
            mp[b]++;    // 해당 종류에 cnt
        }
        
        // 경우의 수는 long long으로
        long long ret = 1;
        for(auto c : mp) {
            ret *= ((long long)c.second + 1);   // 해당 종류의 의상의 개수 + 해당 종류에서 아무것도 선택 안했을 때의 경우
        }
        ret--;  // 모든 종류에서 아무 것도 선택하지 않았을 때는 제외
        cout << ret << '\n';
    }
    return 0;
}

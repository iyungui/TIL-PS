#include <bits/stdc++.h>

using namespace std;

int cnt[100];
int a, b, c;
int t[3][2];

int main() {
    cin >> a >> b >> c;
    
    for(int i = 0; i < 3; i++)
        cin >> t[i][0] >> t[i][1];
    
    for(int i = 0; i < 3; i++)
        for(int j =  t[i][0]; j < t[i][1]; j++)
            cnt[j]++;
    
    int ans = 0;
    for(int i = 1; i < 100; i++) {
        if(cnt[i] == 1) {
            ans += a;
        } else if(cnt[i] == 2) {
            ans += (b * 2);
        } else if(cnt[i] == 3) {
            ans += (c * 3);
        }
    }
    cout << ans;
    
    return 0;
}
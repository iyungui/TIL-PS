#include <bits/stdc++.h>

using namespace std;

int t, n;
string a, b;

int main() {
    ios_base::sync_with_stdio();
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> t;
    
    while(t--) {
        cin >> n;
        map<string, int> mp;
        
        for(int i = 0; i < n; i++) {
            cin >> a >> b;
            mp[b]++;
        }
        
        long long ret = 1;
        
        for(auto a : mp) {
            ret *= ((long long)a.second + 1);
        }
        ret--;
        cout << ret << '\n';
    }
    return 0;
}

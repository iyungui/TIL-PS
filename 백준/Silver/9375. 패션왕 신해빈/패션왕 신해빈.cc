#include <bits/stdc++.h>

using namespace std;

int t, n;
map<string, int> mp;
string a, b;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> t;
    
    while(t--) {
        cin >> n;
        
        ll ret = 1;
        mp.clear();
        for(int i = 0; i < n; i++) {
            cin >> a >> b;
            mp[b]++;
        }
        for(auto it : mp) {
            ret *= (ll)it.second + 1;
        }
        ret--;
        cout << ret << '\n';
    }
    
}

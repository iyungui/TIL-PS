#include <bits/stdc++.h>

using namespace std;

int n, m;
string a;
map<string, int> mp;
string arr[100004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        cin >> a;
        mp[a] = i;
        arr[i] = a;
    }
    
    for(int i = 0; i < m; i++) {
        cin >> a;
        if(atoi(a.c_str())) {
            // int
            cout << arr[stoi(a)] << '\n';
        } else {
            // string
            cout << mp[a] << '\n';
        }
    }
    
    return 0;
}

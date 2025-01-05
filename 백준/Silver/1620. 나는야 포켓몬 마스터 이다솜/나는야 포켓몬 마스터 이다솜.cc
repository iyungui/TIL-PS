#include <bits/stdc++.h>

using namespace std;

int n, m;
string s;
string a[100004];   // int to string
map<string, int> mp;    // string to int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> s;
        
        a[i + 1] = s;
        mp[s] = i + 1;
    }
    
    for(int i = 0; i < m; i++) {
        cin >> s;
        if(atoi(s.c_str()) == 0) {
            cout << mp[s] << '\n';
        } else {
            cout << a[stoi(s)] << '\n';
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n, m;
unordered_map<int, int> mp;
int main() {
    cin >> n >> m; 
    for(int i = 0; i < n; i++) {
        int num; cin >> num;
        mp[num]++;
    }
    while(m--) {
        int num; cin >> num;
        cout << mp[num] << " ";
    }
    return 0;
}
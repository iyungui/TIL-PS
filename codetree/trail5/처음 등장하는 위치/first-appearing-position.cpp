#include <bits/stdc++.h>
using namespace std;

int n;
map<int, int> mp;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int num; cin >> num;
        if(mp.find(num) == mp.end()) mp[num] = i + 1;
    }
    for(auto& [num, pos] : mp) {
        cout << num << " " << pos << '\n';
    }
    return 0;
}
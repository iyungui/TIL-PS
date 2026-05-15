#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int, int>> p;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        p.push_back({b, a});
    }
    sort(p.begin(), p.end());

    int cnt = 0;
    int last_end = -1;
    for(auto& pp : p) {
        if(pp.second > last_end) {
            cnt++;
            last_end = pp.first;
        }
    }
    cout << cnt << '\n';
    return 0;
}
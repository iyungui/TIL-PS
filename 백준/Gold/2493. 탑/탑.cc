#include<bits/stdc++.h>

using namespace std;

int n, h;
stack<pair<int, int>> tower;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    tower.push({100000004, 0});
    for(int i = 1; i <= n; i++) {
        cin >> h;
        while(tower.top().first <= h) tower.pop();
        cout << tower.top().second << " ";
        tower.push({h, i});
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int n, m;

void combi(int idx, vector<int> &b) {
    if(b.size() == m) {
        for(int i : b) cout << i << " ";
        cout << '\n';
        return;
    }
    for(int i = idx + 1; i <= n; i++) {
        b.push_back(i);
        combi(i, b);
        b.pop_back();
    }
    return;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    vector<int> b;
    combi(0, b);
    return 0;
}
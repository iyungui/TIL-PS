#include <bits/stdc++.h>
using namespace std;

vector<int> blocks;

void go(int s, int e) {
    vector<int> tmp;
    for(int i = 0; i < (int)blocks.size(); i++) {
        if(i < s || i > e) {
            tmp.push_back(blocks[i]);
        }
    }
    blocks = tmp;
}

int main() {
    int n; cin >> n;
    blocks.resize(n);
    for(int i = 0; i < n; i++) cin >> blocks[i];
    
    int s, e;
    cin >> s >> e; go(s-1, e-1);
    cin >> s >> e; go(s-1, e-1);

    cout << (int)blocks.size() << '\n';
    for(int x : blocks) {
        cout << x << '\n';
    }
    return 0;
}
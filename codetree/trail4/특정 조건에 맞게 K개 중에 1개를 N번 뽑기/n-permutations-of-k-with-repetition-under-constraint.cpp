#include <iostream>
#include <vector>
using namespace std;

int K, N;
vector<int> b;

void solve() {
    for(int num : b) cout << num << " ";
    cout << '\n';
}

void go(int idx) {
    if(idx == N) {
        solve();
        return;
    }
    for(int i = 1; i <= K; i++) {
        if(idx >= 2 && b[idx-1] == b[idx-2] && b[idx-1] == i) continue;
        b.push_back(i);
        go(idx+1);
        b.pop_back();
    }
}

int main() {
    cin >> K >> N;

    go(0);
    
    return 0;
}

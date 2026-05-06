#include <bits/stdc++.h>
using namespace std;

int ret, N;

bool chk(vector<int>& v) {
    int prev = v[0];
    int cnt = 1;

    for(int i = 1; i < N; i++) {
        if(v[i] == prev) {
            cnt++;
        }
        else {
            if(cnt % prev != 0) return 0;
            else cnt = 1;
        }
        prev = v[i];
    }
    if(cnt % prev != 0) return 0;
    return 1;
}

void go(vector<int>& v) {
    if((int)v.size() == N) {
        if(chk(v)) ret++;
        return;
    }
    for(int i = 1; i <= 4; i++) {
        v.push_back(i);
        go(v);
        v.pop_back();
    }
}

int main() {
    // Please write your code here.
    cin >> N;
    vector<int> b;
    go(b);
    cout << ret << '\n';
    return 0;
}

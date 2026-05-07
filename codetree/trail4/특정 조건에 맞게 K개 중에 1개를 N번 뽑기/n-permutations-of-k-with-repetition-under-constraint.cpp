#include <bits/stdc++.h>
using namespace std;

int K, N;
vector<vector<int>> v;

bool chk(vector<int>& b) {
    int cnt = 1;
    for(int i = 0; i < (int)b.size(); i++) {
        if(i > 0 && b[i-1] == b[i]) {
            cnt++;
            if(cnt >= 3) return 0;
        }
        else if(b[i-1] != b[i]) cnt = 1;
    }
    return 1;
}

void go(int cnt, vector<int>& b) {
    // N개 숫자를 다 뽑은 경우
    if(cnt == N) {
        if(chk(b)) v.push_back(b);
        return;
    }
    for(int i = 1; i <= K; i++) {
        b.push_back(i);
        go(cnt+1, b);
        b.pop_back();
    }
}

int main() {
    cin >> K >> N;
    vector<int> b;
    go(0, b);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(vector<int>& vv : v) {
        for(int i : vv) cout << i << " ";
        cout << '\n';
    }
    return 0;
}
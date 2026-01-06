#include<bits/stdc++.h>

using namespace std;

int n, s, w, cnt;
// 각 계란의 내구도, 무게
vector<pair<int, int>> eggs;
int ret; 

void solve(int idx) {
    // base case: 마지막 계란까지 다 든 경우
    if(idx == n) {
        ret = max(ret, cnt);
        return;
    }

    // 1.현재 들고 있는 계란이 이미 깨져있는 경우 or 다른 모든 계란 깨져있으면 패스
    if(eggs[idx].first <= 0 || cnt == n - 1) {
        solve(idx + 1);
        return;
    }

    // 2.다른 계란들을 하나씩 쳐본다.
    for(int i = 0; i < n; i++) {
        // 자기 자신 or 이미 깨진 계란은 continue
        if(i == idx || eggs[i].first <= 0) continue;

        // action
        eggs[i].first -= eggs[idx].second;
        eggs[idx].first -= eggs[i].second;
        if(eggs[i].first <= 0) cnt++;
        if(eggs[idx].first <= 0) cnt++;
        
        // recurse: 다음 계란으로 이동
        solve(idx + 1);

        // backtrack(reset)
        if(eggs[i].first <= 0) cnt--;
        if(eggs[idx].first <= 0) cnt--;
        eggs[i].first += eggs[idx].second;
        eggs[idx].first += eggs[i].second;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        // 각 계란의 내구도와 무게를 입력받음
        cin >> s >> w;
        eggs.push_back({s, w});
    }

    solve(0);

    cout << ret << '\n';
    return 0;
}
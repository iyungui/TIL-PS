#include<bits/stdc++.h>

using namespace std;

int n, s, w;
// 각 계란의 내구도, 무게
vector<pair<int, int>> eggs;
int ret; 

// 깨진 계란 개수 세기
int count() {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(eggs[i].first <= 0) cnt++;
    }
    return cnt;
}

void solve(int idx) {
    // base case:: 마지막 계란까지 다 든 경우
    if(idx == n) {
        ret = max(ret, count());
        return;
    }

    // 1.현재 들고 있는 계란이 이미 깨져있는 경우는 다음 계란으로 패스
    if(eggs[idx].first <= 0) {
        solve(idx + 1);
        return;
    }

    // 계란을 하나라도 쳤는지 확인하는 flag
    bool hit = false;

    // 2.다른 계란들을 하나씩 쳐본다.
    for(int i = 0; i < n; i++) {
        // 자기 자신 or 이미 깨진 계란은 continue
        if(i == idx || eggs[i].first <= 0) continue;

        // action
        eggs[i].first -= eggs[idx].second;
        eggs[idx].first -= eggs[i].second;
        hit = true;

        // recurse: 다음 계란으로 이동
        solve(idx + 1);

        // backtrack(reset)
        eggs[i].first += eggs[idx].second;
        eggs[idx].first += eggs[i].second;
    }

    // 3. 하나도 못 친경우(나 빼고 다 깨져있는 경우는 그냥 넘어가기)
    if(!hit) solve(idx+1);
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
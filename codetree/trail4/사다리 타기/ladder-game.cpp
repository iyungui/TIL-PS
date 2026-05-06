#include<bits/stdc++.h>
using namespace std;

int N, M;
vector<pair<int, int>> ladder;
vector<int> selected;
vector<int> original;
int ret = 20;

vector<int> get_result(const vector<int>& active_idx) {
    vector<int> res(N + 1);
    for(int i = 0; i < N; i++) res[i] = i;  // 처음에는 세로줄 번호로 시작

    vector<pair<int, int>> cur_ladders;
    for(int idx : active_idx) cur_ladders.push_back(ladder[idx]);

    for(auto& l : cur_ladders) {
        int a = l.second;
        swap(res[a], res[a + 1]);
    }
    
    return res;
}

void go(int idx, int cnt) {
    if(idx == M) {
        if(get_result(selected) == original) {
            ret = min(ret, cnt);
        }
        return;
    }

    selected.push_back(idx);
    go(idx + 1, cnt + 1);
    selected.pop_back();
    go(idx + 1, cnt);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        ladder.push_back({b, a - 1});
    }
    sort(ladder.begin(), ladder.end());

    // 모든 가로줄을 선택한 경우, 결과 배열 만들기
    vector<int> all_selected;
    for(int i = 0; i < M; i++) all_selected.push_back(i);
    original = get_result(all_selected);

    go(0, 0);

    cout << ret << '\n';
    return 0;
}
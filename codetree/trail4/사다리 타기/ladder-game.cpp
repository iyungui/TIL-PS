#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> ladder;
vector<int> original;
vector<int> selected, all_selected;
int ret = 20;
vector<int> get_result(vector<int>& active_idx) {
    vector<int> res(n);

    for(int i = 0; i < n; i++) res[i] = i;
    
    for(int idx : active_idx) {
        int a = ladder[idx].second;
        if(a < n - 1) swap(res[a], res[a + 1]);
    }

    return res;
}

void go(int idx, int cnt) {
    if(idx == m) {
        if(get_result(selected) == original) {
            ret = min(ret, cnt);
        }
        return;
    }
    // idx번째 가로줄을 선택하는 경우
    selected.push_back(idx);
    go(idx + 1, cnt + 1);
    selected.pop_back();

    // 선택하지 않는 경우
    go(idx + 1, cnt);
}


int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        ladder.push_back({b, a-1}); // 가로줄(위에서 부터 아래 순으로) 기준 정렬
    }
    sort(ladder.begin(), ladder.end());
    
    // m개의 모든 가로줄을 사용한 결과 구해놓기
    for(int i = 0; i < m; i++) all_selected.push_back(i);
    original = get_result(all_selected);

    go(0, 0);
    cout << ret << '\n';
    return 0;
}
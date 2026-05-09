#include <bits/stdc++.h>
using namespace std;

// 1. 각 동전의 번호와 위치를 배열에 담기
// 2. 오름차순으로 최소 3개의 동전을 뽑는 조합 코드 작성
// 3. 해당 조합에서의 맨해튼 거리 합 구하기
pair<int, int> coins[10];
pair<int, int> s, e;
int n;
bool has_coin[10];
int ret = 1e9;

int get_dist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

// 현재 보고있는 동전 번호 cur
// 마지막으로 선택한 동전의 번호 last, 
// 지금까지 모은 동전의 개수 cnt,
// 현재까지의 최소이동거리 dist
void go(int cur, int last, int cnt, int dist) {
    // 3개의 동전을 모았다면 그 때마다 최솟값 갱신
    if(cnt >= 3) ret = min(ret, dist + get_dist(coins[last], e));

    // 마지막 동전까지 다 탐색한 경우
    if(cur > 9) return;

    if(9-last < 3-cnt && cnt < 3) return;

    if(has_coin[cur]) {
        int nxt_dist;
        if(cnt == 0) nxt_dist = get_dist(s, coins[cur]);
        else nxt_dist = get_dist(coins[last], coins[cur]);
        go(cur+1, cur, cnt+1, dist + nxt_dist);
    }
    go(cur+1, last, cnt, dist);
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        string row; cin >> row;
        for(int j = 0; j < n; j++) {
            if(row[j] == 'S') s = {i, j};
            else if(row[j] == 'E') e = {i, j};
            else if(isdigit(row[j])) {
                int num = row[j] - '0';
                coins[num] = {i, j};
                has_coin[num] = true;
            }
        }
    }

    go(1, 0, 0, 0);
    if(ret == 1e9) cout << -1 << '\n';
    else cout << ret << '\n';
    return 0;
}
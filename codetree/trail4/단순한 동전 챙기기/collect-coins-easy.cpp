#include <bits/stdc++.h>
using namespace std;

// 1. 각 동전의 번호와 위치를 배열에 담기
// 2. 오름차순으로 최소 3개의 동전을 뽑는 조합 코드 작성
// 3. 해당 조합에서의 맨해튼 거리 합 구하기
pair<int, int> coins[10];
pair<int, int> s, e;
int n;
bool has_coin[10];
int chosen[10];
int ret = 1e9;

int get_dist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int get_total_dist(int m) {
    int total = get_dist(s, coins[chosen[0]]);    // 시작점부터 첫번째 동전까지의 거리
    for(int i = 1; i < m; i++) {
        total += get_dist(coins[chosen[i-1]], coins[chosen[i]]);
    }
    total += get_dist(coins[chosen[m-1]], e);
    return total;
}

// 마지막으로 선택한 동전의 번호 last, 
// 지금까지 모은 동전의 개수 cnt
void go(int last, int cnt) {
    // 3개의 동전을 모았다면 그 때마다 최솟값 갱신
    if(cnt >= 3) ret = min(ret, get_total_dist(cnt));

    // 마지막 동전까지 다 탐색한 경우
    if(last == 9) return;

    if(9-last < 3-cnt && cnt < 3) return;

    int nxt = last+1;
    if(has_coin[nxt]) {
        chosen[cnt] = nxt;
        go(nxt, cnt+1);
    }
    go(nxt, cnt);
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

    go(0, 0);
    if(ret == 1e9) cout << -1 << '\n';
    else cout << ret << '\n';
    return 0;
}
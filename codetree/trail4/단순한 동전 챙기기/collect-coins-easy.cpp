#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
// 어떤 순서로 동전을 방문할지
// S -> c[1] -> c[2] -> c[3] -> E 로 동전을 선택했을 때,
// 사이사이의 맨해튼 거리의 총합을 구하고 최솟값 갱신

// d[k][i] = i번째 동전을 수집했을 때, 총 k개의 동전을 수집한 경우 최소 이동 거리
int d[11][10];  //[수집개수][마지막동전번호]
struct Point { int y, x; };
Point coins[10];
bool has_coin[10];  // 해당 동전이 있는지 여부
Point s, e;
int n;

int get_dist(Point a, Point b) {
    return abs(a.y - b.y) + abs(a.x - b.x);
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        string row; cin >> row;
        for(int j = 0; j < n; j++) {
            if(row[j] == 'S') s = {i, j};
            else if(row[j] == 'E') e = {i, j};
            else if(isdigit(row[j])) {
                int num = row[j] - '0';   // 동전번호
                coins[num] = {i, j};
                has_coin[num] = true;
            }
        }
    }

    // dp 배열 초기화
    for(int i = 0; i <= 10; i++) {
        for(int j = 0; j < 10; j++) {
            d[i][j] = INF;
        }
    }

    // 시작점에서 각 동전까지의 거리
    for(int i = 0; i < 10; i++) {
        if(has_coin[i]) d[1][i] = get_dist(s, coins[i]);
    }

    // 이전동전(j)에서 다음동전(i)으로 이동(j < i)
    for (int k = 2; k <= 9; k++) { // 수집한 동전의 총 개수
        for (int i = 1; i <= 9; i++) { // 현재 도달한 동전 번호
            if (!has_coin[i]) continue;
            for (int j = 1; j < i; j++) { // 이전에 도달했던 동전 번호
                if (has_coin[j] && d[k - 1][j] != INF) {
                    d[k][i] = min(d[k][i], d[k - 1][j] + get_dist(coins[j], coins[i]));
                }
            }
        }
    }

    // 최소 3개의 동전을 모으고 도착점으로 이동
    int ret = INF;
    for(int k = 3; k <= 9; k++) {
        for(int i = 1; i <= 9; i++) {
            if(has_coin[i] && d[k][i] != INF) {
                ret = min(ret, d[k][i] + get_dist(coins[i], e));
            }
        }
    }
    if(ret == INF) cout << -1 << '\n';
    else cout << ret << '\n';
    return 0;
}
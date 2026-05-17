#include <bits/stdc++.h>
using namespace std;

// k: 0부터 N*N까지.
// 모든시작점(N*N)에 대하여, 격자 내 임의의 점이 마름모 안에 들었는지 체크 (맨헤튼거리)=> 골드수익과 금의 개수 구하기
// 골드수익(benefit) 과 cost (k.. 공식) 중 benefit이 더 크거나 같을 때
// 금의 개수가 더 많다면, 최대 금의 개수 갱신 
int n, m;
int grid[24][24];

int get_dist(int y1, int x1, int y2, int x2) {
    return abs(y1 - y2) + abs(x1 - x2);
}

int go(int y, int x, int k) {
    if(k == 0) return grid[y][x];

    int cnt = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(get_dist(i, j, y, x) <= k) {
                cnt += grid[i][j];
            }
        }
    }

    return cnt;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    int max_cnt = 0;
    for(int k = 0; k <= n*n; k++) {
        int cost = (k*k) + (k+1)*(k+1);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int gold_cnt = go(i, j, k);
                int benefit = gold_cnt * m;
                if(benefit >= cost && gold_cnt > max_cnt) max_cnt = gold_cnt;
            }
        }
        
    }
    cout << max_cnt << '\n';
    return 0;
}
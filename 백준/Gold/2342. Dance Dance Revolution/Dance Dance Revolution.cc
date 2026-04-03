#include<bits/stdc++.h>
using namespace std;

int d[100004][5][5];    // d[i][l][r]: i번째 단계에 위치가 l,r 일때까지 사용되는 최소의 힘 
// 지시사항을 담은 배열
int a[100004];
const int INF = 0x3f3f3f3f;

int get_cost(int from, int to) {
    if(from == 0) return 2;
    if(from == to) return 1;
    if(abs(from - to) == 2) return 4;
    return 3;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n = 0;
    while(1) {
        int num; cin >> num;
        if(num == 0) break;
        a[n++] = num;
    }

    memset(d, 0x3f, sizeof(d));
    d[0][0][0] = 0;

    for(int i = 0; i < n; i++) {
        int target = a[i];
        for(int l = 0; l < 5; l++) {
            for(int r = 0; r < 5; r++) {
                // 아직 도달하지 못하는 상태인 경우
                if(d[i][l][r] == INF) continue;

                // 왼발이 움직이는 경우(단, 오른발이 타겟에 가있는 경우 제외)
                if(r != target) {
                    // 다음 단계(i+1)에서 목표지점(target, r)에 놓이게 되는 상태를 업데이트
                    // 기존에 구해둔 최소비용(d[i+1][target][r])과 비교하여 최소비용으로 업데이트
                    d[i+1][target][r] = min(d[i+1][target][r], get_cost(l, target) + d[i][l][r]);
                }
                if(l != target) {
                    d[i+1][l][target] = min(d[i+1][l][target], get_cost(r, target) + d[i][l][r]);
                }
            }
        }
    }

    // n번째 단계까지 도달하는 힘 중에 최솟값 출력
    int ans = INF;
    for(int l = 0; l < 5; l++) {
        for(int r = 0; r < 5; r++) {
            ans = min(ans, d[n][l][r]);
        }
    }
    cout << ans << '\n';
    return 0;
}
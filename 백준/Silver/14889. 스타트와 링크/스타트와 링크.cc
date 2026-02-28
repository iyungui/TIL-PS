#include<bits/stdc++.h>
using namespace std;

int n;
int s[22][22];
int min_diff = 1e9;
bool is_start[22];  // 누가 스타트 팀인지 체크

void calc() {
    int st = 0;
    int li = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            // i, j 모두 스타트 팀원일 경우
            if(is_start[i] && is_start[j]) {
                // s[i][j]의 능력치를 합산
                // s[j][i]는 이전/이후 반복문에서 계산
                st += s[i][j];
            }
            // i, j 모두 링크 팀인 경우
            else if(!is_start[i] && !is_start[j]) {
                li += s[i][j];
            }
        }
    }

    // 팀 능력치 차이 계산
    int diff = abs(st - li);
    min_diff = min(min_diff, diff);
    return;
}

void solve(int idx, int cnt) {
    // 스타트 팀원을 n/2명 구했을 경우
    if(cnt == n / 2) {
        calc(); // 스타트와 링크 팀 능력치 차이 계산하고 갱신
        return;
    }
    for(int i = idx; i < n; i++) {
        is_start[i] = 1;    // 스타트 팀원으로 등록
        solve(i+1, cnt+1);
        is_start[i] = 0;    // 등록해제. 원복
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // s[i][j]는 i번, j번 사람이 같은 팀에 속했을때 팀에 더해지는 능력치.

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
    }
    
    // n 개 중 n/2개를 고르는 조합 (스타트팀의 조합을 구해보자)
    is_start[0] = 1;
    solve(1, 1);    // 1번인덱스부터. 그리고 1개의 스타트팀원을 구한상태

    cout << min_diff << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int max_val[12][12];
int N, M, C;
int W[12][12];
int sum, ret;

void get_max_val(int r, int c, int w_sum, int val_sum, int cnt) {
    if(cnt == M) {  // 연속된 M개를 전부 탐색한 경우
        sum = max(sum, val_sum);
        return;
    }

    if(w_sum + W[r][c] <= C) get_max_val(r, c + 1, w_sum + W[r][c], val_sum + W[r][c]*W[r][c], cnt + 1);
    get_max_val(r, c + 1, w_sum, val_sum, cnt + 1);
}

bool chk(int r1, int c1, int r2, int c2) {
    if(r1 == r2) {  // 같은 행을 탐색하는 경우
        if(abs(c1-c2) < M) return 0;   // 간격이 M미만은 겹침
        else return 1;  // 간격이 M 이상이면 안겹침
    }
    // 다른 행을 탐색하는 경우, 안겹침
    return 1;
}

int main() {
    cin >> N >> M >> C;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> W[i][j];
        }
    }
    // max_val[r][c] = 시작점 (r,c)에서 시작하여 연속한 M개의 물건 중, 무게의 합이 C이하인 '조합' 중, 최대가치의 합
    for(int r = 0; r < N; r++) {
        for(int c = 0; c <= N - M; c++) {
            sum = 0;
            get_max_val(r, c, 0, 0, 0);
            max_val[r][c] = sum;
        }
    }

    // 겹치지 않는 두 도둑의 시작점(r1, c1), (r2,c2) 에 대하여. 최대 가치 값 구하기
    for(int r1 = 0; r1 < N; r1++) {
        for(int c1 = 0; c1 <= N - M; c1++) {
            for(int r2 = 0; r2 < N; r2++) {
                for(int c2 = 0; c2 <= N - M; c2++) {
                    // 두 도둑의 영역이 겹치지 않는다면
                    if(chk(r1, c1, r2, c2)) ret = max(ret, max_val[r1][c1] + max_val[r2][c2]);
                }
            }
        }
    }

    cout << ret << '\n';
    return 0;
}
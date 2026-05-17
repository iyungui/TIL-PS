#include <bits/stdc++.h>
using namespace std;

// 1. 만들 수 있는 모든 직사각형을 다 찾기
// 2. 그중 두 개를 골랐을 때 안 겹치면 합을 계산해서 최댓값 갱신

int n, m;
int grid[5][5];

// 직사각형의 좌표와 합을 저장
struct Rect {
    int r1, c1, r2, c2;
    int sum;
};

bool isOK(Rect a, Rect b) {
    // a가 b의 완전히 위/아래/왼쪽/오른쪽에 있는 경우가 하나라도 있으면 겹치지 않음
    if(a.r2 < b.r1 || a.r1 > b.r2 || a.c2 < b.c1 || a.c1 > b.c2) return 1;

    return 0;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<Rect> rects;

    // 1. 만들 수 있는 모든 직사각형을 찾기 및 합 계산
    // (r1, c1): 좌측상단 지점, (r2,c2): 우측하단 지점
    for(int r1 = 0; r1 < n; r1++) {
        for(int c1 = 0; c1 < m; c1++) {
            for(int r2 = r1; r2 < n; r2++) {
                for(int c2 = c1; c2 < m; c2++) {
                    int cur_sum = 0;
                    for(int i = r1; i <= r2; i++) {
                        for(int j = c1; j <= c2; j++) {
                            cur_sum += grid[i][j];
                        }
                    }
                    rects.push_back({r1, c1, r2, c2, cur_sum});
                }
            }
        }
    }

    // 겹치지 않는 두 직사각형을 선택하여 최대 합 구하기
    // 2중 for문 조합 사용
    int max_sum = -1e9;
    int k = rects.size();
    for(int i = 0; i < k; i++) {
        for(int j = i+1; j < k; j++) {
            // 겹치지 않는다면 최대값 갱신
            if(isOK(rects[i], rects[j])) max_sum = max(max_sum, rects[i].sum + rects[j].sum);
        }
    }

    cout << max_sum << '\n';
    return 0;
}
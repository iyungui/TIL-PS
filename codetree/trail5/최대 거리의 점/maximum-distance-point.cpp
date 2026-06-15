#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> points;

bool canPlace(int dist) {
    int cnt = 1;                 // 첫 점에 설치
    int last = points[0];

    for (int i = 1; i < N; i++) {
        if (points[i] - last >= dist) {
            cnt++;
            last = points[i];
        }
    }

    return cnt >= M;
}

int main() {
    cin >> N >> M;

    points.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> points[i];
    }

    sort(points.begin(), points.end());

    int left = 1;
    int right = points[N - 1] - points[0];
    int answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (canPlace(mid)) {
            answer = mid;      // 가능한 거리
            left = mid + 1;    // 더 큰 거리 시도
        } else {
            right = mid - 1;   // 거리 줄이기
        }
    }

    cout << answer << '\n';

    return 0;
}
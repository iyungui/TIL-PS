#include <bits/stdc++.h>
using namespace std;

int getDist(pair<int, int>& a, pair<int, int>& b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
    int n; cin >> n;
    vector<pair<int, int>> points(n);
    vector<int> L(n), R(n);
    for(int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    L[0] = 0;
    for(int i = 1; i < n; i++) {
        L[i] = L[i-1] + getDist(points[i-1], points[i]);
    }

    R[n-1] = 0;
    for(int i = n-2; i >= 0; i--) {
        R[i] = R[i+1] + getDist(points[i], points[i+1]);
    }

    int ret = 1e9;
    for(int i = 1; i < n-1; i++) {
        // i번째 포인트를 건너뛰는 경우
        int dist = getDist(points[i-1], points[i+1]) + L[i-1] + R[i+1];
        ret = min(ret, dist);
    }

    cout << ret << '\n';

    return 0;
}
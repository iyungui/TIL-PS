#include <bits/stdc++.h>
using namespace std;
// 최댓값이 K라고 하자. K가 작아지면, 필요한 레인 수가 많아지고, K가 커지면 필요한 레인 수가 줄어든다
// 딱 M개의 레인을 사용하기 위한 K중 최솟값을 찾자

int n, m;
vector<int> t;

bool chk(int k) {
    int lane_cnt = 0;
    int lane_time = 0;
    for(int i = 0; i < n; i++) {
        if(t[i] > k) return 0;  // 한 사람의 이용시간이 k보다 크다면, 불가능

        if(lane_time + t[i] > k) {
            lane_cnt++;
            lane_time = 0;
        }
        lane_time += t[i];
    }
    return (lane_cnt+1) <= m;
}

int main() {
    cin >> n >> m;
    t.resize(n);
    int low = 1;
    int high = 0;
    for(int i = 0; i < n; i++) {
        cin >> t[i];
        high += t[i];
    }

    int ret = high;

    while(low <= high) {
        int k = low + (high - low) / 2;
        // 레인별로 K를 넘지않도록 이용시간 배정했을 때, M개의 레인을 사용한다면
        if(chk(k)) {
            // 더 작은 k 탐색
            high = k - 1;
            ret = min(ret, k);
        }
        // M개의 레인보다 더 사용한다면
        else {
            low = k + 1;
        }
    }

    cout << ret << '\n';
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// 해당 숙련도로 제한 시간 내에 해결 가능한지 확인하는 함수
bool is_possible(int level, const vector<int>& diffs, const vector<int>& times, ll limit) {
    ll total_time = 0;
    int n = diffs.size();

    for (int i = 0; i < n; i++) {
        int diff = diffs[i];
        int time_cur = times[i];

        if (diff <= level) {
            // 숙련도가 충분한 경우
            total_time += time_cur;
        } else {
            // 숙련도가 부족한 경우: (틀린 횟수) * (현재 소요 + 이전 소요) + 현재 소요
            int time_prev = (i == 0) ? 0 : times[i - 1];
            ll mistakes = diff - level;
            total_time += mistakes * (ll)(time_cur + time_prev) + time_cur;
        }

        // 중간에 이미 제한 시간을 초과하면 바로 실패 반환
        if (total_time > limit) return false;
    }

    return total_time <= limit;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int lo = 1;
    int hi = 0;
    for (int d : diffs) hi = max(hi, d); // 난이도 중 최댓값을 상한선으로 설정

    int answer = hi;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (is_possible(mid, diffs, times, limit)) {
            // 더 낮은 숙련도가 있는지 확인
            answer = mid;
            hi = mid - 1;
        } else {
            // 숙련도가 더 높아야 함
            lo = mid + 1;
        }
    }

    return answer;
}
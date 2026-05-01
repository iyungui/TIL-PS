#include <bits/stdc++.h>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int i = n-1, j = n-1;
    // n개의 집을 모두 탐색. (역순으로)
    while(i >= 0  || j >= 0) {
        // 배달해야할 집 탐색
        while(i >= 0 && deliveries[i] == 0) i--;
        // 수거해야할 집 탐색
        while(j >= 0 && pickups[j] == 0) j--;
        
        // 이동거리 계산
        int dist = (max(i, j)+1) * 2;
        answer += dist;
        
        // 배달 처리
        int cnt = cap;
        while(i >= 0 && cnt > 0) {
            // i번째 집에 cnt 다 배달하는 경우
            if(deliveries[i] >= cnt) {
                deliveries[i] -= cnt;
                cnt = 0;
            }
            else {
                cnt -= deliveries[i];
                deliveries[i] = 0;
                i--;
            }
        }
        
        cnt = cap;
        while(j >= 0 && cnt > 0) {
            // i번째 집에 cnt 다 배달하는 경우
            if(pickups[j] >= cnt) {
                pickups[j] -= cnt;
                cnt = 0;
            }
            else {
                cnt -= pickups[j];
                pickups[j] = 0;
                j--;
            }
        }
    }
    return answer;
}
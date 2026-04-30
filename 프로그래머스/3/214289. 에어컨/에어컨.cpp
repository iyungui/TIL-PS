#include <bits/stdc++.h>

using namespace std;

int d[1004][54];
const int INF = 0x3f3f3f3f;
int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    memset(d, INF, sizeof(d));
    int offset = 10;
    int temp = temperature + offset;    // 실외 온도
    int low = t1 + offset, high = t2 + offset;
    int n = onboard.size();
    
    // 0분 시점에 실외 온도로 설정하는 경우 드는 비용은 0
    d[0][temp] = 0;
    
    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= 50; j++) {
            // 승객이 타고있는 시간에 범위를 벗어나는 온도는 무시
            if(onboard[i] == 1 && (j < low || j > high)) continue;
            
            // Case 1: 온도를 유지하는 경우(에어컨 켜고 유지하는 경우와, 에어컨 끄고 유지하는 경우)
            // -- 실외온도temp와 실내온도 j가 같은경우에만 에어컨을 껐을 때 온도가 유지됨
            if(temp == j) d[i][j] = min(d[i][j], d[i-1][j]);
            d[i][j] = min(d[i][j], d[i-1][j] + b);
            
            // Case 2: 에어컨을 켜고 온도 올리거나, 끄고 올라가는 경우(j-1 < temp)
            if(j > 0) {
                if(temp > j-1) d[i][j] = min(d[i][j], d[i-1][j-1]);
                d[i][j] = min(d[i][j], d[i-1][j-1] + a);
            }
            
            // 3. 에어컨을 켜고 온도 내리거나, 끄고 내려가는 경우(j+1 > temp)
            if(j < 50) {
                if(temp < j+1) d[i][j] = min(d[i][j], d[i-1][j+1]);
                d[i][j] = min(d[i][j], d[i-1][j+1] + a);
            }
        }
    }
    
    // 마지막 시간(n-1)의 모든 온도 중 최솟값
    int answer = INF;
    for(int j = 0; j <= 50; j++) answer = min(answer, d[n-1][j]);
    return answer;
}
#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    int x = routes.size();  // 로봇의 수
    int m = routes[0].size();   // 하나의 로봇이 거쳐가야 할 포인트 개수
    int n = points.size();  // points 개수
    
    // [시간대][로봇좌표] = 로봇개수
    unordered_map<int, int> log[20004];
    int mx = 0;
    
    for(int i = 0; i < x; i++) {
        // 시작시간 초기화
        int cur = 0;
        // i번째 로봇이 가야할 경로 탐색
        for(int j = 0; j < m-1; j++) {
            // 시작 포인트 a, 도착 포인트 b 추출
            int a = routes[i][j] - 1;
            int b = routes[i][j+1] - 1;
            // 각 포인트의 y,x 좌표 추출
            int sy = points[a][0], sx = points[a][1];
            int ey = points[b][0], ex = points[b][1];
            
            // 시작시간(0초), 시작지점(sy,sx)에 1카운트
            if(j == 0) log[cur][sy*100+sx]++;
            
            // r(y)부터 이동
            while(sy != ey) {
                // up
                if(sy > ey) sy--;
                // down
                else sy++;
                // 기록
                log[++cur][sy*100+sx]++;
            }
            
            // 그리고 c(x) 이동
            while(sx != ex) {
                // right -> left
                if(sx > ex) sx--;
                // left -> right
                else sx++;
                // 기록
                log[++cur][sy*100+sx]++;
            }
        }
        mx = max(mx, cur);
    }
    
    // log 순회하면서, [특정시간][특정좌표]에 로봇개수가 2이상인 경우의 수 모두 구하기
    for(int t = 0; t <= mx; t++) {
        for(auto const& [p, cnt] : log[t]) {
            if(cnt >= 2) answer++;
        }
    }
    
    return answer;
}
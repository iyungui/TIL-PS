#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    const int x = routes.size();    // 로봇의 개수
    const int m = routes[0].size(); // 로봇 한 대가 방문할 포인트 수
    
    /*
    -각 로봇의 매 이동을 (시간 t, 좌표r,c)의 정수 하나로 인코딩 하고 events벡터에 푸시
    // 인코딩 공식: t * 10201 + r * 101 + c
    //   - r, c는 최대 100이므로 101을 곱해 자릿수를 분리
    //   - 101 * 101 = 10201로 t 자릿수 분리
    //   - 역으로 디코딩: t = key/10201, r = (key%10201)/101, c = key%101
    */
    vector<int> events;
    events.reserve(x * 20000);
    for(int i = 0; i < x; i++) {    // 각 로봇 순회
        // 0초에서 출발
        int t = 0;
        int r = points[routes[i][0]-1][0];
        int c = points[routes[i][0]-1][1];
        
        // 포인트 각 구간 순회
        for(int j = 0; j < m - 1; j++) {
            int er = points[routes[i][j+1]-1][0];
            int ec = points[routes[i][j+1]-1][1];
            
            // 첫번째 구간의 출발지점만 따로 기록
            if(j==0) events.push_back(t*10201+r*101+c);
            
            while(r != er) {
                r += (er > r) ? 1 : -1;
                events.push_back(++t * 10201 + r * 101 + c);
            }
            while(c != ec) {
                c += (ec > c) ? 1 : -1;
                events.push_back(++t * 10201 + r * 101 + c);
            }
        }
    }
    
    sort(events.begin(), events.end());
    int answer = 0;
    for(int i = 0, n = events.size(); i < n; ) {
        int j = i;
        while(j < n && events[j] == events[i]) j++;
        if(j-i >= 2) answer++;
        i = j;
    }
    return answer;
}
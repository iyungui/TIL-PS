#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    // 현재 다리를 0으로 초기화
    // 다리는 앞과 뒤 O(1)에 접근 하도록 덱으로 초기화
    deque<int> bri;
    for(int i = 0; i < bridge_length; i++) bri.push_back(0);

    int i = 0;  // 지나갈 트럭 추적
    int n = truck_weights.size();
    // 시간 추적
    int t = 0;
    // 현재 다리 위 무게 추적
    int cur_w = 0;
    
    while(i < n) {
        // 다리에서 빠져나가는거 확인
        if(!bri.empty()) {
            cur_w -= bri.front();
            bri.pop_front();
        }
        
        // 현재 트럭이 다리에 올라갈 수 있는 경우.
        if(cur_w + truck_weights[i] <= weight) {
            cur_w += truck_weights[i];
            bri.push_back(truck_weights[i]);
            i++;    // 다음 트럭 추적
        }
        // 현재 트럭이 다리에 올라갈 수 없으면 0을 추가
        else {
            bri.push_back(0);
        }
        t++;    // 1초 경과
    }
    // n번째 트럭을 다리에 올리고. 남은 트럭 지나갈 때까지 카운트
    while(!bri.empty()) {
        t++;
        bri.pop_front();
    }
    return t;
}
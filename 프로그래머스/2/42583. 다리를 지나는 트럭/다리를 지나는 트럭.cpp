#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    int idx = 0;
    int cur_weight = 0;
    queue<pair<int, int>> bridge;
    
    while (idx < truck_weights.size() || bridge.size()) {
        time++;
        
        // 다리에서 나갈 트럭 확인
        if (bridge.size() && bridge.front().second == time) {
            cur_weight -= bridge.front().first;
            bridge.pop();
        }
        
        // 다리에 진입할 트럭 확인
        if (idx < truck_weights.size()) {
            int truck = truck_weights[idx];
            if (bridge.size() < bridge_length && cur_weight + truck <= weight) {
                bridge.push({truck, time + bridge_length});
                cur_weight += truck;
                idx++;
            }
        }
    }
    return time;
}
#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int t = 0;
    int cur_weight = 0;
    int truck_idx = 0;
    queue<pair<int, int>> bridge;
    
    while(truck_idx < truck_weights.size() || !bridge.empty()) {
        t++;
        // 다리에서 나갈 트럭 처리
        if (!bridge.empty() && bridge.front().second == t) {
            cur_weight -= bridge.front().first;
            bridge.pop();
        }
        
        // 새 트럭 진입 시도
        if (truck_idx < truck_weights.size()) {
            int truck = truck_weights[truck_idx];
            
            if (bridge.size() < bridge_length &&
               cur_weight + truck <= weight) {
                bridge.push({truck, t + bridge_length});
                cur_weight += truck;
                truck_idx++;
            }
        }
    }
    return t;
}
import Foundation

func solution(_ bridge_length: Int, _ weight: Int, _ truck_weights: [Int]) -> Int {
    // 시간 카운터
    var time = 0
    
    // 다리 위 트럭 상태 관리 (0은 빈 공간을 의미)
    var bridge = Array(repeating: 0, count: bridge_length)
    
    // 다리 위 트럭의 총 무게
    var currentWeight = 0
    
    // 대기 중인 트럭 큐
    var waitingTrucks = truck_weights
    
    // 모든 트럭이 다리를 건널 때까지 반복
    while !waitingTrucks.isEmpty || currentWeight > 0 {
        // 시간 증가
        time += 1
        
        // 1. 다리 끝에 도달한 트럭 제거
        let truckLeavingBridge = bridge.removeFirst()
        currentWeight -= truckLeavingBridge
        
        // 2. 새 트럭이 다리에 진입할 수 있는지 확인
        if !waitingTrucks.isEmpty {
            let nextTruck = waitingTrucks[0]
            
            // 새 트럭이 다리에 진입할 수 있는 경우
            if currentWeight + nextTruck <= weight {
                waitingTrucks.removeFirst()
                bridge.append(nextTruck)
                currentWeight += nextTruck
            } else {
                // 무게 초과로 진입 불가능한 경우 빈 공간 추가
                bridge.append(0)
            }
        } else {
            // 남은 트럭이 없는 경우 빈 공간 추가
            bridge.append(0)
        }
    }
    
    return time
}
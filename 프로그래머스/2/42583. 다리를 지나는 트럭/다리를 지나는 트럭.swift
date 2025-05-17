
import Foundation

func solution(_ bridge_length:Int, _ weight:Int, _ truck_weights:[Int]) -> Int {
    var trucks = truck_weights
    var bridge = Array(repeating: 0, count: bridge_length)
    var t = 0
    var curWeight = 0
    
    while !bridge.isEmpty {
        curWeight -= bridge.removeFirst()
        t += 1
        
        if bridge.count < bridge_length {
            if let curTruck = trucks.first {
                if curTruck + curWeight <= weight {
                    curWeight += trucks.removeFirst()
                    bridge.append(curTruck)
                } else {
                    bridge.append(0)
                }
            }
        }
    }
    
    return t
}

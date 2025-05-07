import Foundation

func solution(_ s: String) -> [Int] {
    var components = [Int: Int]()
    
    s.split { !$0.isNumber }.map { Int(String($0))! }.forEach {
        components[$0, default: 0] += 1
    }
    
    return components.sorted { $0.value > $1.value }.map { $0.key }
}
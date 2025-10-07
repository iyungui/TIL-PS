import Foundation

func solution(_ s:String) -> [Int] {
    var cnt = [Int: Int]()
    _ = s.split { !$0.isNumber }.map { Int(String($0))! }.forEach { cnt[$0, default: 0] += 1 }
    return cnt.sorted { $0.value > $1.value }.map { $0.key }
}
import Foundation

func solution(_ numbers:[Int]) -> Int {
    let n = numbers.sorted(by: >)
    return max(n[0] * n[1], n[n.count - 1] * n[n.count - 2])
}
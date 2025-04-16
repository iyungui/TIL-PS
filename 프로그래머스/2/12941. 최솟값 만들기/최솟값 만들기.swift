import Foundation

func solution(_ A:[Int], _ B:[Int]) -> Int {
    let a = A.sorted(), b = B.sorted(by: >)
    var ans: Int = 0
    for i in 0..<a.count {
        ans += a[i] * b[i]
    }
    return ans
}
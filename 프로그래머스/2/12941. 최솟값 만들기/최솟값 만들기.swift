import Foundation

func solution(_ A:[Int], _ B:[Int]) -> Int {
    let a = A.sorted(), b = B.sorted(by: >)
    var ans: Int = 0
    for (aItem, bItem) in zip(a, b) {
        ans += aItem * bItem
    }
    return ans
}
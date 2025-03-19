import Foundation

func solution(_ score:[[Int]]) -> [Int] {
    let total = score.map { $0.reduce(0, +) }
    let sortedTotal = total.sorted(by: >)
    return total.map {
        (sortedTotal.firstIndex(of: $0) ?? 0) + 1
    }
}

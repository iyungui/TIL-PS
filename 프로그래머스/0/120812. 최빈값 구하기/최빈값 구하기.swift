import Foundation
func solution(_ array:[Int]) -> Int {
    let group = Dictionary.init(grouping: array) { $0 }
    let max = group.map { $0.1.count }.max()
    let maxGroup = group.filter { $0.1.count == max }
    return maxGroup.count > 1 ? -1 : maxGroup.keys.first!
}
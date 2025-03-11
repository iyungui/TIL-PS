import Foundation

func solution(_ numbers:[Int]) -> Int {
    var result = 0
    for i in (0..<numbers.count) {
        for j in (i + 1..<numbers.count) {
            result = max(result, numbers[i] * numbers[j])
        }
    }
    return result
}
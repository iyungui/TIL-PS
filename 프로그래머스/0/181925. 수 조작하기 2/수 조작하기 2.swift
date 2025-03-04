import Foundation

func solution(_ numLog:[Int]) -> String {
    let diff: [Int: String] = [1: "w", -1: "s", 10: "d", -10: "a"]
    return zip(numLog, numLog.dropFirst()).map { diff[$1 - $0]! }.joined()
}
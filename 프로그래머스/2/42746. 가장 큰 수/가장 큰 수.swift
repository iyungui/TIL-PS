import Foundation

func solution(_ numbers:[Int]) -> String {
    let a = numbers.map { String($0) }.sorted(by: { $0 + $1 > $1 + $0 }).joined()
    return a.first! == "0" ? "0" : a
}
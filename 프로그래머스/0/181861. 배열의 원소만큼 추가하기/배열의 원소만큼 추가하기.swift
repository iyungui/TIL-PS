import Foundation

func solution(_ arr:[Int]) -> [Int] {
    return arr.flatMap { Array(repeatElement($0, count: $0)) }
}
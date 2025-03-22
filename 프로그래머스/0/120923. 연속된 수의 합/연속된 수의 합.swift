import Foundation

func solution(_ num: Int, _ total: Int) -> [Int] {
    let x = (total - (num * (num - 1) / 2)) / num
    return (0..<num).map { $0 + x }
}
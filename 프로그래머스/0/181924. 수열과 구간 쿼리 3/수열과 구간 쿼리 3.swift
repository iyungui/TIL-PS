import Foundation

func solution(_ arr: [Int], _ queries: [[Int]]) -> [Int] {
    var arr = arr
    // forEach
    queries.forEach {
        arr.swapAt($0[0], $0[1])
    }
    return arr
}
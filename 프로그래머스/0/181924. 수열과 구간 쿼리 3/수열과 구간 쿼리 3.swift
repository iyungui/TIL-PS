import Foundation

func solution(_ arr:[Int], _ queries:[[Int]]) -> [Int] {
    var result = arr
    queries.forEach { query in
        result.swapAt(query[0], query[1])
    }
    return result
}
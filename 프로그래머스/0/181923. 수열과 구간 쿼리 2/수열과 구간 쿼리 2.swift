import Foundation

func solution(_ arr:[Int], _ queries:[[Int]]) -> [Int] {
    return queries.map { 
        let (s, e, k) = ($0[0], $0[1], $0[2])
        return Array(arr[s...e]).filter { $0 > k }.min() ?? -1
    }
}
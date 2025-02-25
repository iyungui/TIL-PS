import Foundation

func solution(_ arr:[Int], _ queries:[[Int]]) -> [Int] {
    var arr = arr
    queries.forEach { num in
        let (s, e, k) = (num[0], num[1], num[2])
        (s...e).forEach { if $0 % k == 0 { arr[$0] += 1 } }
    }
    return arr
}
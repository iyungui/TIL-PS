import Foundation

func solution(_ arr:[Int], _ queries:[[Int]]) -> [Int] {
    var arr = arr
    queries.forEach { num in
        let (s, e, k) = (num[0], num[1], num[2])
        for i in s...e {
            if i % k == 0 {
                arr[i] += 1
            }
        }
    }
    return arr
}
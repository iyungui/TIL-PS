
import Foundation


var arr: [Int] = []

for _ in 0..<9 { arr.append(readLine().map { Int($0)! }!) }
let sum = arr.reduce(0, +)

func solve() -> (Int, Int) {
    for i in 0..<9 {
        for j in 0..<i {
            if sum - arr[i] - arr[j] == 100 {
                return (i, j)
            }
        }
    }
    return (0, 0)
}

let (x, y) = solve()

var result: [Int] = []
for i in 0..<9 {
    if i == x || i == y { continue }
    result.append(arr[i])
}
result.sorted().forEach { print($0) }
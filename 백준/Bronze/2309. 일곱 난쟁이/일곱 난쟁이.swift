import Foundation
var arr: [Int] = []

for _ in 0..<9 {
    arr.append(Int(readLine()!)!)
}

var a = 0, b = 0
let sum = arr.reduce(0, +)
for i in 0..<9 {
    for j in 0..<i {
        if sum - arr[i] - arr[j] == 100 {
            a = i; b = j
            break
        }
    }
}

let res = arr.enumerated()
    .filter { $0.offset != a && $0.offset != b }
    .sorted { $0.element < $1.element }

for (_, value) in res {
    print(value)
}
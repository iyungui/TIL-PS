import Foundation

// 주차 요금 A, B, C
let temp = readLine()!.components(separatedBy: " ").map { Int($0)! }
let a = temp[0], b = temp[1], c = temp[2]

var arr2: [[Int]] = []

for _ in 0..<3 {
    let temp: String = readLine()!
    arr2.append(temp.components(separatedBy: " ").map { Int($0)! })
}

var cnt = Array(repeating: 0, count: 100)

arr2.forEach { num in
    for i in num[0]..<num[1] {
        cnt[i] += 1
    }
}
var result: Int = 0
for i in cnt {
    if i == 1 {
        result += (a * 1)
    } else if i == 2 {
        result += (b * 2)
    } else if i == 3 {
        result += (c * 3)
    }
}

print(result)
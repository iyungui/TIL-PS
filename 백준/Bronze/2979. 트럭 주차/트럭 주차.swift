import Foundation

let arr = readLine()!.components(separatedBy: " ").map { Int($0)! }
let a = arr[0], b = arr[1], c = arr[2]
var cnt: Array<Int> = Array(repeating: 0, count: 100)
for _ in 0..<3 {
    let temp = readLine()!.components(separatedBy: " ").map { Int($0)! }
    for i in temp[0]..<temp[1] {
        cnt[i] += 1
    }
}
var res: Int = 0
for i in cnt {
    switch i {
    case 1: res += i * a
    case 2: res += i * b
    case 3: res += i * c
    default: continue
    }
}
print(res)
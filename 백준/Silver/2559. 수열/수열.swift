
import Foundation

let input = readLine()!.split(separator: " ").map { Int($0)! }
let n = input[0], k = input[1]
let temp = readLine()!.split(separator: " ").map { Int($0)! }

var curSum = 0
for i in 0..<k {
    curSum += temp[i]
}

var ret = curSum

for i in k..<n {
    curSum = curSum + temp[i] - temp[i - k]
    ret = max(ret, curSum)
}

print(ret)
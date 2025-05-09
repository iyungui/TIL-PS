import Foundation

let a = readLine()!.components(separatedBy: " ").map { Int($0)! }

var n: Int = a[0], k: Int = a[1]

let arr = readLine()!.components(separatedBy: " ").map { Int($0)! }

var psum = Array(repeating: 0, count: 100001)

for i in 1...n {
    psum[i] = psum[i - 1] + arr[i - 1]
}

var res = Int.min

for i in k...n {
    res = max(res, psum[i] - psum[i - k])
}

print(res)
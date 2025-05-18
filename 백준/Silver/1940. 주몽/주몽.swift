import Foundation
let n = Int(readLine()!)!
let m = Int(readLine()!)!
let nums = readLine()!.components(separatedBy: " ").map { Int($0)! }.sorted()
var cnt = 0
var (l, r) = (0, n - 1)
while l < r {
    let sum = nums[l] + nums[r]
    if sum == m { cnt += 1 }
    if sum <= m { l += 1 }
    else { r -= 1 }
}
print(cnt)

import Foundation

let N = Int(readLine()!)!
let M = Int(readLine()!)!
let nums = readLine()!.components(separatedBy: " ").map { Int($0)! }
var cnt = 0

if M > 200000 { print(0) }
else {
    for i in 0..<N {
        for j in 0..<i {
            if nums[i] + nums[j] == M { cnt += 1 }
        }
    }
    print(cnt)
}

import Foundation

let n = Int(readLine()!)!
let students = readLine()!.split(separator: " ").map { Int($0)! }

let bc = readLine()!.split(separator: " ").map { Int($0)! }
let b = bc[0]
let c = bc[1]

var ret: Int64 = 0

for cnt in students {
    ret += 1    // 각 시험장마다 총감독관 1명
    
    let remain = cnt - b
    if remain > 0 {
        let d = Int64(ceil(Double(remain) / Double(c)))
        ret += d
    }
}

print(ret)

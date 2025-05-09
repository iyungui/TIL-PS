
import Foundation

var t = Int(readLine()!)!

while t > 0 {
    
    let n = Int(readLine()!)!
    var dict: [String: Int] = [:]
    
    for _ in 0..<n {
        let str = readLine()!.components(separatedBy: " ")
        dict[str[1], default: 0] += 1
    }
    let res = dict.values.reduce(1) { $0 * ($1 + 1) } - 1
    print(res)
    t -= 1
}
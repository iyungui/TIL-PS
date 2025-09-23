
import Foundation

let s = readLine()!
var flag = false
var i = 0

while i < s.count {
    let startIndex = s.index(s.startIndex, offsetBy: i)
    
    // check pi, ka
    if i < s.count - 1 {
        let endIndex = s.index(startIndex, offsetBy: 2)
        let substr = String(s[startIndex..<endIndex])
        if substr == "pi" || substr == "ka" {
            i += 2
            continue
        }
    }
    
    // check chu
    if i < s.count - 2 {
        let endIndex = s.index(startIndex, offsetBy: 3)
        let substr = String(s[startIndex..<endIndex])
        if substr == "chu" {
            i += 3
            continue
        }
    }
    
    flag = true
    break
}

print(flag ? "NO" : "YES")

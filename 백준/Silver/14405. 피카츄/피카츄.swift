
import Foundation

let s = Array(readLine()!)
var flag = false

var i = 0
while i < s.count {
    if i <= s.count - 2 && (String(s[i..<i+2]) == "pi" || String(s[i..<i+2]) == "ka") {
        i += 2
    } else if i <= s.count - 3 && String(s[i..<i+3]) == "chu" {
        i += 3
    } else {
        flag = true
        break
    }
}

print(flag ? "NO" : "YES")
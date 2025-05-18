import Foundation

let n = Int(readLine()!)!
var cnt = 0
for _ in 0..<n {
    let word = readLine()!
    var stk = Array<Character>()
    for ch in word {
        if !stk.isEmpty && stk.last! == ch {
            stk.removeLast()
        } else {
            stk.append(ch)
        }
    }
    if stk.isEmpty {
        cnt += 1
    }
}

print(cnt)
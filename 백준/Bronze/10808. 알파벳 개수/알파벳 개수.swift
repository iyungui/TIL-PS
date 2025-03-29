import Foundation

let s = readLine()!
var cnt = [Int](repeating: 0, count: 26)

for char in s {
    cnt[Int(char.asciiValue!) - 97] += 1
}
print(cnt.map { String($0) }.joined(separator: " "))


import Foundation

let s = readLine()!
var cnt = [Int](repeating: 0, count: 26)

for char in s {
    let index = Int(char.asciiValue! - Character("a").asciiValue!)
    cnt[index] += 1
}
print(cnt.map { String($0) }.joined(separator: " "))

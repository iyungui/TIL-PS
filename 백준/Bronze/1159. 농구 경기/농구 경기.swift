import Foundation

let num: Int = Int(readLine()!)!
var cnt: Array<Int> = Array(repeating: 0, count: 26)
for _ in 0..<num {
    let s: Array<Character> = Array(readLine()!)
    cnt[Int(s[0].asciiValue! - 97)] += 1
}

let startingValue = Int(("a" as UnicodeScalar).value) // 97
var res: String = ""

for (offset, element) in cnt.enumerated() {
    if element >= 5 {
        let c: Character = Character(UnicodeScalar(offset + startingValue)!)
        res += String(c)
    }
}
if res.isEmpty { print("PREDAJA") }
else {
    print(res.sorted().map { String($0) }.joined())
}
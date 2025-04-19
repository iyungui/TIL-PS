import Foundation

let s: [Character] = Array(readLine()!)
var res: [Character] = []
for ch in s {
    if ch.isLowercase {
        let ascii = ch.asciiValue!
        let temp = (ascii - 97 + 13) % 26 + 97
        res.append(Character(UnicodeScalar(temp)))
    } else if ch.isUppercase {
        let ascii = ch.asciiValue!
        let temp = (ascii - 65 + 13) % 26 + 65
        res.append(Character(UnicodeScalar(temp)))
    } else {
        res.append(ch)
    }
}

print(String(res))
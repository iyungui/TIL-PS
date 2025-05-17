import Foundation

var s: [Character] = Array(readLine()!)

var cnt: [Character: Int] = [:]

for a in s {
    cnt[a, default: 0] += 1
}

var flag = 0
var flag2: Bool = false
var mid: Character = " "
var ret: [Character] = []
for i in (UnicodeScalar("A").value...UnicodeScalar("Z").value).reversed() {
    let c = Character(UnicodeScalar(i)!)
    if(cnt[c] != nil) {
        if(cnt[c]! % 2 == 1) {
            flag += 1
            mid = c
            flag2 = true
            cnt[c]! -= 1
        }
        if flag == 2 { break }
        for _ in stride(from: 0, to: cnt[c]!, by: 2) {
            ret.append(c)
            ret.insert(c, at: 0)
        }
    }
}
if(flag2) {
    ret.insert(mid, at: ret.count / 2)
}
if flag == 2 {
    print("I'm Sorry Hansoo")
} else {
    print(String(ret))
}

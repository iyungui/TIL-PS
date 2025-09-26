import Foundation

let n = Int(readLine()!)!

var cur = 1
for i in stride(from: n - 1, through: 0, by: -1) {
    for _ in 0..<i { print(" ", terminator: "") }
    for j in 0..<cur {
        print("*", terminator: "")
        if j == cur - 1 { print() }
    }
    cur += 2
}
cur -= 2
for i in 1..<n {
    cur -= 2
    for _ in 0..<i { print(" ", terminator: "") }
    for j in 0..<cur {
        print("*", terminator: "")
        if j == cur - 1 { print() }
    }
}
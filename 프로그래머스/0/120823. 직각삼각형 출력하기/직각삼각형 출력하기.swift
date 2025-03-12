import Foundation

let n = Int(readLine()!)!

for i in 1...n {
    for j in 1...i {
        print("*", terminator: "")
    }
    print()
}

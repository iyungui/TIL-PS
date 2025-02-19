import Foundation

func solution(_ n:Int, _ control:String) -> Int {
    let op: [Character: Int] = ["w": 1, "s": -1, "d": 10, "a": -10]
    return n + control.reduce(0) { $0 + op[$1]! }
}
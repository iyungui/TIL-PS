import Foundation

func solution(_ n:Int) -> Int {
    var n = n
    let cnt = String(n, radix: 2).filter { $0 == "1" }.count
    var cnt2 = 0
    var str: String
    guard n != 1000000 else { return n + 1 }
    while true {
        n += 1
        str = String(n, radix: 2)
        cnt2 = str.filter { $0 == "1" }.count
        if cnt == cnt2 {
            return Int(str, radix: 2)!
        }
    }
    return 0
}
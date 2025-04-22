import Foundation

func solution(_ n:Int) -> Int {
    var n = n
    var cnt1 = String(n, radix: 2).filter { $0 == "1" }.count
    while true {
        n += 1
        var cnt2 = String(n, radix: 2).filter { $0 == "1" }.count
        if cnt1 == cnt2 {
            break
        }
    }
    return n
}